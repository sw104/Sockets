/*
 * Copyright 2016 Sam White
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Base Socket class definition.
#ifndef SOCKET_H
#define SOCKET_H

#define LOGGING         //Log socket messages.
#ifdef LOGGING
    #define LOGLVL1     //Basic logging: connections/disconnections.
    #ifdef LOGLVL1
        #define LOGLVL2 //Enhanced logging: sent/received messages.
    #endif
    #define LOGMSG      //Log to console.
    #define LOGFILE     //Write log file.
#endif

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#ifdef LOGMSG
    #include <iostream> //Message logging only.
#endif

#include "SocketException.h"    //Socket specific exceptions.
#ifdef LOGFILE
    #include "LogFile.h"    //File logging operations.
#endif

    class Socket    //Generic socket properties.
    {
	
        private:
            int fd;                 //Socket file descriptor.
            #ifdef LOGFILE
                LogFile socketLog;  //Define Log object.
            #endif

        protected:
            Socket();                           //Default constructor (empty).
            Socket(int fd);                     //Constructor.
            ~Socket();                          //Destructor - closes socket.
            void setSocket(int fd);             //Set socket file descriptor.
            int getSocket();                    //Get socket file descriptor.
            #ifdef LOGGING
                void log(std::string message);  //Log message.
            #endif
    };

#endif
