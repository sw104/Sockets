//Server Socket Implementation.
#include "ServerSocket.h"

//Private Methods:

ServerSocket::create(int port)
{
    serverAddr.sin_port = htons(port);  //Set port number in a network byte order.
    serverAddr.sin_family = AF_INET;    //Set type TCP.
    serverAddr.sin_addr.s_addr = INADDR_ANY;    //Address of server.
    setSocket(socket(AF_INET, SOCK_STREAM, 0));	    //Open socket.
    if (getSocket() < 0)
        throw SocketException("Server Socket Creation: Error opening socket");
    if (bind(getSocket(), (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)    //Bind the socket to the sepcified port.
        throw SocketException("Error binding socket to port");
}

//Public Methods:

ServerSocket::ServerSocket()    //Default constructor.	
{
}

ServerSocket::ServerSocket(int port)
{
    create(port);
}

ServerSocket::~ServerSocket()
{
}

void ServerSocket::listen(int port)
{
    create(port);
    listen();
}

void ServerSocket::listen()
{
    listen(getSocket(), 5);	//Listen on socket, max. 5 queued connections.
    clientLen = sizeof(clientAddr);
}

int ServerSocket::accept()
{
    int clientfd = accept(getSocket(), (struct sockaddr*)&clientAddr, &clientLen);	//Accept client connection.
    if (clientfd < 0)
        throw SocketException("Server Socket Creation: Error accepting new client connection");
    return clientfd;
}
