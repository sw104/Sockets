//Operable Socket class definition.
#ifndef OPERABLESOCKET_H
#define OPERABLESOCKET_H

#define DEBUGMSG    //If defined debug messages will be shown.

#include <cstring>  //strcpy.

#include <string>   //Normal string operations.
#include <utility>  //std::pair
#ifdef DEBUGMSG //Only include if debug messages are to be included.
    #include <iostream> //Debugging only.
#endif

#include "Socket.h" //Generic Socket functions.

    class OperableSocket: public Socket
    {
        private:
            int bufferSize;                                             //Current size of the message buffer.
            unsigned char* buffer;                                      //Message buffer.		
            int readMessageLength();                                    //Read incomming message length.
            void readMessage(int length);                               //Read incomming message of supplied length.
            void writeMessage(const unsigned char* message, int length);//Write message of supplied length.

        protected: 
            const unsigned char* getMessage();                          //Read incomming message and return buffer.
            const unsigned char* getMessage(int length);                //Read incomming message and return buffer. Ensure the message sent is the length asked for.
            std::pair<const unsigned char*, int> getMessageAndLength(); //Read the sent message and return it and its length. 
            void sendMessage(const unsigned char* message, int length); //Send a raw bytes message of the specified length.
        
        public:
            OperableSocket(int socket);                     //Constructor - calls Socket constructor and sets socket fd.
            ~OperableSocket();                              //Destructor.
            virtual void sendMessage(std::string message);  //Send an std::string message.
            virtual std::string fetchMessage();             //Fetch message written to socket.
    };
	
#endif
