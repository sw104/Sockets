//Client Socket Implementation.
#include "ClientSocket.h"

//Public Methods:

ClientSocket::ClientSocket()
{
}

ClientSocket::ClientSocket(std::string host, int port)
{
    connect(host, port);
}

void ClientSocket::connect(std::string host, int port)   //Create socket and set connection to given host and port.
{
    server = gethostbyname(host.c_str());   //Resolve hostname.
    if (server == NULL)
        throw SocketException("Client Socket Creation: Error resolving hostname");
    bzero((char*) &serverAddr, sizeof(serverAddr));    //Clear serverAddr contents.
    serverAddr.sin_port = htons(port);  //Set port in a network byte order.
    serverAddr.sin_family = AF_INET;    //TCP socket.
    bcopy((char*)server->h_addr, (char*)&serverAddr.sin_addr.s_addr, server->h_length);    //Copy server address information to serverAddr.
    setSocket(socket(AF_INET, SOCK_STREAM, 0)); //Open socket.
    if (getSocket() < 0)
        throw SocketException("Client Socket Creation: Error opening socket");
    if (::connect(getSocket(), (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)    //Connect to server.
        throw SocketException("Client Socket Connection: Error connecting to server");
}
