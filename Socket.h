//Base Socket Class.
#ifndef SOCKET_H
#define SOCKET_H

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include "SocketException.h"    //Socket specific exceptions.

    class Socket
    {
	
        private:
            int fd;         //The socket file descriptor.	
            void close();   //Close socket.

        protected:
            Socket();               //Default constructor.
            Socket(int fd);         //Constructor - set socket file descriptor value.
            ~Socket();              //Destructor - closes socket.
            void setSocket(int fd); //Set the socket file descriptor.
            int getSocket();        //Get the socket file descriptor.
    };

#endif
