//Operable Socket class implementation.
#include "OperableSocket.h"

//Private methods:

int OperableSocket::readMessageLength()
{
    int msgLen = 0;    //Message length.
    int bytesRead = 0;    //Bytes read on last read.
    int totalBytesRead = 0;
    //Read incomming message length and ignore heatbeat/blank messages.
    while (totalBytesRead < 4 && msgLen == 0)
    {
        bytesRead = read(getSocket(), &msgLen + totalBytesRead, 4 - totalBytesRead);
        if (bytesRead < 0)
            throw SocketException("Message Length Reading: Error reading message length");
        else if (bytesRead == 0)
            throw SocketException("Message Length Reading: Client disconnected");
        totalBytesRead += bytesRead;
    }
    return msgLen;
}

void OperableSocket::readMessage(int length)
{
    if (length > bufferSize)    //If buffer is too small resize it,
    {
        delete[] buffer;
        buffer = new unsigned char[bufferSize = length];
    }
    int bytesRead = 0;  //Bytes read on last pass.
    int totalBytesRead = 0; 
    bzero(buffer, bufferSize);  //Reset buffer values.
    //Read incomming message.
    while (totalBytesRead < length)
    {
        bytesRead = read(getSocket(), buffer + totalBytesRead, length - totalBytesRead);    //Read the sent message.
        if (bytesRead < 0)
            throw SocketException("Message Reading: Error reading sent message");
        else if (bytesRead == 0)
            throw SocketException("Message Reading: Client disconnected");
        totalBytesRead += bytesRead;
	}
    #ifdef LOGLVL2
        std::string msg((char*)buffer, length);
        log("Received message: " + msg);
    #endif
}

void OperableSocket::writeMessage(const unsigned char* message, int length)
{
    int bytesWritten = 0;   //Bytes written on last pass.
    int totalBytesWritten = 0;
    //Write message.
    while (totalBytesWritten < length)
    {
        bytesWritten = write(getSocket(), message + totalBytesWritten, length - totalBytesWritten);
        if (bytesWritten < 0) 
            throw SocketException("Message Writing: Error writing message");
        if (bytesWritten == 0)
            throw SocketException("Message Length Writing: Client disconnected");
        totalBytesWritten += bytesWritten;
    }
}

//Protected methods:

OperableSocket::OperableSocket()
{
    buffer = new unsigned char[bufferSize = 16];
}

const unsigned char* OperableSocket::getMessage(int length)
{
    int msgLen = readMessageLength();
    if (msgLen != length)   //Check actual length against required length.
        throw SocketException("Message Retrieval: Requested message length not actual stated message length");
    readMessage(msgLen);
    return buffer;
}

std::pair <const unsigned char*, int> OperableSocket::getMessageAndLength()
{
    int msgLen = readMessageLength();
    readMessage(msgLen);
    std::pair<const unsigned char*, int> returnVal (buffer, msgLen);
    return returnVal;
}

void OperableSocket::sendMessage(const unsigned char* message, int length)
{
    writeMessage((unsigned char*)&length, 4);   //Write message length to first 4 bytes.
    writeMessage(message, length);
    #ifdef LOGLVL2
        std::string msg((char*)message, length);
        log("Sent message: " + msg);
    #endif 
}

//Public methods:

OperableSocket::OperableSocket(int socket) : Socket(socket)	//Pass socket fd to Socket class through constructor.
{
    buffer = new unsigned char[bufferSize = 16];
}

OperableSocket::~OperableSocket()
{
    delete[] buffer;
}

void OperableSocket::sendMessage(std::string message)
{
    const unsigned char* cMsg = (unsigned char*)message.c_str();    //Convert string into raw bytes.
    sendMessage(cMsg, message.length());
}

std::string OperableSocket::fetchMessage()
{
    std::pair<const unsigned char*, int> msgAndLen(getMessageAndLength());
    std::string str((char*)std::get<0>(msgAndLen), std::get<1>(msgAndLen)); //Convert raw bytes message into string.
    return str;
}
