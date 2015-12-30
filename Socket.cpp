//Base Socket class implementation.
#include "Socket.h"

//Protected methods:

Socket::Socket()
{
}

Socket::Socket(int fd)
{
    setSocket(fd); 
}

Socket::~Socket()
{
    ::close(fd);
}

void Socket::setSocket(int fd)
{
    this->fd = fd;
}

int Socket::getSocket()
{
    return fd;
}
