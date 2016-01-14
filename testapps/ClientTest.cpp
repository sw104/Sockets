/*
 * To the extent possible under law, the person who associated CC0 with
 * this work has waived all copyright and related or neighboring rights
 * to this work.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 */
//Client socket test application.
#include "ClientSocket.h"   //Client socket operations.

int main()
{
    try
    {
        ClientSocket socket("localhost", 1653); //Connect to socket on local machine - port number is arbitrary.
        socket.sendMessage("Test.");    //Send message on socket.
        std::cout << socket.fetchMessage() << std::endl;    //Print returned message.
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl; //Print any exceptions.
    }
    return 0;
}
