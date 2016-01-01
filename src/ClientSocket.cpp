//Client Socket class implementation.
#include "ClientSocket.h"

//Public methods:

ClientSocket::ClientSocket()
{
}

ClientSocket::ClientSocket(std::string host, int port, int keepAlive)
{
    connect(host, port, keepAlive);
}

void ClientSocket::connect(std::string host, int port, int keepAlive)   //Create socket and set connection to given host and port.
{
    socklen_t optLen = sizeof(keepAlive);   //Size of keepalive option.
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
    if (setsockopt(getSocket(), SOL_SOCKET, SO_KEEPALIVE, &keepAlive, optLen) < 0)  //Set TCP keepalive option.
        throw SocketException("Client Socket Creation: Error setting socket options");
    if (::connect(getSocket(), (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)    //Connect to server.
        throw SocketException("Client Socket Connection: Error connecting to server");
    #ifdef LOGLVL1
        log("Client Socket: Connected to host");
    #endif
}
