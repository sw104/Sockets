//Base Socket Class Implementation.
#include "Socket.h"

//Private methods:

void Socket::close()
{
    ::close(fd);
}

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
    close();
}

void Socket::setSocket(int fd)
{
    this->fd = fd;
}

int Socket::getSocket()
{
    return fd;
}
