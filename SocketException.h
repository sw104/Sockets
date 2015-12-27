//Header file of SocketException class.
#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <exception>

    class SocketException : public std::exception   //Class to handle socket related exceptions.
    {
        private:
            const char* message;    //Exception message.
        public:
            SocketException(const char* message);       //Create Exception and store message.
            virtual const char* what() const throw();   //Get Exception message details - overides Exception class method.
    };

#endif
