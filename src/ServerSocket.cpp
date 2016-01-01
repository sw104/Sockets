//Server Socket class implementation.
#include "ServerSocket.h"

//Public methods:

ServerSocket::ServerSocket()	
{
}

ServerSocket::ServerSocket(int port, int keepAlive)
{
    listen(port, keepAlive);
}

void ServerSocket::listen(int port, int keepAlive)
{
    socklen_t optLen = sizeof(keepAlive);   //Size of keepalive option.
    serverAddr.sin_port = htons(port);  //Set port number in a network byte order.
    serverAddr.sin_family = AF_INET;    //Set type TCP.
    serverAddr.sin_addr.s_addr = INADDR_ANY;    //Address of server.
    setSocket(::socket(AF_INET, SOCK_STREAM, 0));   //Open socket.
    if (getSocket() < 0)
        throw SocketException("Server Socket Creation: Error opening socket");
    if (setsockopt(getSocket(), SOL_SOCKET, SO_KEEPALIVE, &keepAlive, optLen) < 0)  //Set TCP keepalive option.
        throw SocketException("Server Socket Creation: Error setting socket options");
    if (::bind(getSocket(), (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0)    //Bind socket to port.
        throw SocketException("Server Socket Binding: Error binding socket to port");
    ::listen(getSocket(), 5);	//Listen on socket, max. 5 queued connections.
    clientLen = sizeof(clientAddr);
    #ifdef LOGLVL1
        log("Server Socket: Listening for clients");
    #endif
}

int ServerSocket::accept()
{
    int clientfd = ::accept(getSocket(), (struct sockaddr*)&clientAddr, &clientLen);	//Accept client connection.
    if (clientfd < 0)
        throw SocketException("Server Socket Accepting: Error accepting new client connection"); 
    #ifdef LOGLVL1
        log("Server Socket: Accepted new client");
    #endif
    return clientfd;
}
