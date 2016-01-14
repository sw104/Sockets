/*
 * Copyright 2016 Sam White
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
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
