/*
 * Copyright 2016 Sam White
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Client Socket class definition.
#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <netdb.h>  //Client specific library defining hostent.

#include "OperableSocket.h" //Writable and readable socket properties.

    class ClientSocket: public OperableSocket   //Client-specific properties.
    {
        private:
            struct sockaddr_in serverAddr;  //Server address information.
            struct hostent *server;         //Details of the host server on internet.

        public:
            ClientSocket();                                                 //Default contructor (empty).
            ClientSocket(std::string host, int port, int keepAlive = 1);   //Constructor - calls connect().
            void connect(std::string host, int port, int keepAlive = 1);   //Connect to host on port. "keepAlive" enables/disables TCP keepalive.
    };

#endif
