//Server Socket class definition.
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "Socket.h" //Generic socket properties.

    class ServerSocket: public Socket
    {
        struct sockaddr_in serverAddr, clientAddr;	//serverAddr - address of server, clientAddr - address of connected client. 
        socklen_t clientLen;						//Size of the client address.

        public:
            ServerSocket();			//Default constructor (empty).
            ServerSocket(int port); //Constructor - calls listen(). 
            void listen(int port);	//Opens socket on port and listens.
            int accept();   		//Accept client connection and return client file descriptor.
	};

#endif
