//Server Socket Implementation.
#include "ServerSocket.h"

//Public Methods:

ServerSocket::ServerSocket()    //Default constructor.	
{
}

ServerSocket::ServerSocket(int port)
{
    listen(port);
}

void ServerSocket::listen(int port)
{ 
    serverAddr.sin_port = htons(port);  //Set port number in a network byte order.
    serverAddr.sin_family = AF_INET;    //Set type TCP.
    serverAddr.sin_addr.s_addr = INADDR_ANY;    //Address of server.
    setSocket(::socket(AF_INET, SOCK_STREAM, 0));	    //Open socket.
    if (getSocket() < 0)
        throw SocketException("Server Socket Creation: Error opening socket");
    if (::bind(getSocket(), (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0)    //Bind the socket to the sepcified port.
        throw SocketException("Error binding socket to port");
    ::listen(getSocket(), 5);	//Listen on socket, max. 5 queued connections.
    clientLen = sizeof(clientAddr);
}

int ServerSocket::accept()
{
    int clientfd = ::accept(getSocket(), (struct sockaddr*)&clientAddr, &clientLen);	//Accept client connection.
    if (clientfd < 0)
        throw SocketException("Server Socket Creation: Error accepting new client connection");
    return clientfd;
}
