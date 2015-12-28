//Base Socket class definition.
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
            int fd;         //Socket file descriptor.

        protected:
            Socket();               //Default constructor.
            Socket(int fd);         //Constructor - calls setSocket().
            ~Socket();              //Destructor - closes socket.
            void setSocket(int fd); //Set socket file descriptor.
            int getSocket();        //Get socket file descriptor.
    };

#endif
