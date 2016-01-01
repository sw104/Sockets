#Compiles the client socket test application.
g++ -I src/ --std=c++11 src/Socket.cpp src/SocketException.cpp src/LogFile.cpp src/OperableSocket.cpp src/ClientSocket.cpp testapps/ClientTest.cpp -o bin/clienttest.out
