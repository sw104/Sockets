//Server Socket class definition.
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "Socket.h" //Generic socket properties.

    class ServerSocket: public Socket   //Server-specific socket properties.
    {
        struct sockaddr_in serverAddr, clientAddr;	//serverAddr - address of server, clientAddr - address of connected client. 
        socklen_t clientLen;						//Size of the client address.

        public:
            ServerSocket();			                    //Default constructor (empty).
            ServerSocket(int port, int keepAlive = 1);  //Constructor - calls listen(). 
            void listen(int port, int keepAlive = 1);   //Opens socket on port and listens. "keepAlive" enables/disables TCP keepalive.
            int accept();   		                    //Accept client connection and return client file descriptor.
	};

#endif
