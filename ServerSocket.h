//Server Socket class.
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "Socket.h" //Generic socket properties.

    class ServerSocket: public Socket
    {
        struct sockaddr_in serverAddr, clientAddr;	//serverAddr contains the server address, and clientAddr a connected client address. 
        socklen_t clientLen;						//Contains the size of the address of the client.

        public:
            ServerSocket();			//Default constructor (empty).
            ServerSocket(int port); //Constructor - calls create() with specified port. 
            void listen(int port);	//Calls create() with specified port, then listens on it.
            int accept();   		//Accept a client connection and returns the client file descriptor.
	};

#endif
