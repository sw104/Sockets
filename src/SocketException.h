//SocketException class definition.
#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <exception>    //Generic exception properties.

    class SocketException : public std::exception   //Socket specific exception type.
    {
        private:
            const char* message;    //Exception message.
        public:
            SocketException(const char* message);       //Default constructor - store exception message.
            virtual const char* what() const throw();   //Get Exception message details - overides Exception class method.
    };

#endif
