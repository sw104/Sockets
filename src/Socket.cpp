//Base Socket class implementation.
#include "Socket.h"

//Protected methods:

Socket::Socket()
#ifdef LOGFILE
    : socketLog("Socket Log.txt")   //Construct Log object.
#endif
{
}

Socket::Socket(int fd)
#ifdef LOGFILE
    : socketLog("Socket Log.txt")   //Construct Log object.
#endif
{
    setSocket(fd); 
}

Socket::~Socket()
{
    ::close(fd);
    #ifdef LOGLVL1
        log("Socket closed");
    #endif
}

void Socket::setSocket(int fd)
{
    this->fd = fd;
}

int Socket::getSocket()
{
    return fd;
}

#ifdef LOGGING
    void Socket::log(std::string message)
    {
        #ifdef LOGMSG
            std::cout << message << std::endl;
        #endif
        #ifdef LOGFILE
            socketLog.write(message);
        #endif
    }
#endif
