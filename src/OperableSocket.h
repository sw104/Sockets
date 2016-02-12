/*
 * Copyright 2016 Sam White
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Operable Socket class definition.
#ifndef OPERABLESOCKET_H
#define OPERABLESOCKET_H

#include <cstring>  //bzero.

#include <string>   //Friendly public interface.
#include <utility>  //std::pair.

#include "Socket.h" //Generic Socket properties.

    class OperableSocket: public Socket //Writable and readable socket properties.
    {
        private:
            int bufferSize;                                             //Current size of the message buffer.
            unsigned char* buffer;                                      //Message buffer.		
            int readMessageLength();                                    //Read incomming message length.
            void readMessage(int length);                               //Read incomming message of supplied length.
            void writeMessage(const unsigned char* message, int length);//Write message of supplied length.

        protected: 
            OperableSocket();                                           //Default constructor (empty) - dervied classes must set socket file descriptor.
            const unsigned char* getMessage(int length);                //Read incomming message and return buffer. Require message of given length.
            std::pair<const unsigned char*, int> getMessageAndLength(); //Read the sent message and return it and its length.
            void sendMessage(const unsigned char* message, int length); //Send a raw bytes message of length.
        
        public:
            OperableSocket(int socket);                     //Constructor - calls Socket(int socket) constructor.
            ~OperableSocket();                              //Destructor.
            virtual void sendMessage(std::string message);  //Send an std::string message.
            virtual std::string fetchMessage();             //Fetch message written to socket.
    };
	
#endif
