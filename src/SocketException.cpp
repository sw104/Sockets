//Implementation of SocketException class.
#include "SocketException.h"

//Public methods:

SocketException::SocketException(const char* message)
{
    this->message = message;
}

const char* SocketException::what() const throw()
{
    return message;
}
