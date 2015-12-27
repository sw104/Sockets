//Implementation of SocketException class.
#include "SocketException.h"

SocketException::SocketException(const char* message)
{
    this->message = message;
}

const char* SocketException::what() const throw()
{
    return message;
}
