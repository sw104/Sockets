#Compiles a server socket test application.
g++ -I src/ --std=c++11 src/Socket.cpp src/SocketException.cpp src/LogFile.cpp src/ServerSocket.cpp src/OperableSocket.cpp testapps/ServerTest.cpp -o bin/servertest.out
