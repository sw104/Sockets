//Server socket test application.

#include "ServerSocket.h"   //Server socket operations.
#include "OperableSocket.h" //Communications with clients.

int main()
{
    try
    {
        ServerSocket socket(1653);  //Open socket and listen for clients.
        OperableSocket client(socket.accept()); //Accept client and create OperableSocket object to allow communications.
        std::cout << client.fetchMessage() << std::endl;    //Print sent message.
        client.sendMessage("Test response.");    //Send a response message.
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; //Print any exceptions.
    }
    return 0;
}
