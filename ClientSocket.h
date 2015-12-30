//Client Socket class definition.
#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#define DEBUGMSG    //Display debug messages.

#include <netdb.h>  //Client specific library defining hostent.

#ifdef DEBUGMSG
    #include <iostream> //Debugging only.
#endif

#include "OperableSocket.h" //Read and write operations.

    class ClientSocket: public OperableSocket
    {
        private:
            struct sockaddr_in serverAddr;  //Server address information.
            struct hostent *server;         //Details of the host server on internet.

        public:
            ClientSocket();                                             //Default contructor (empty).
            ClientSocket(std::string host, int port, int keepAlive = 1);   //Constructor - calls connect().
            void connect(std::string host, int port, int keepAlive = 1);   //Connect to host on port. "keepAlive" enables/disables TCP keepalive.
    };

#endif
