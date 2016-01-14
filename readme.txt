C++ socket library for use on Linux systems.

The main library source code is subject to the terms of the Mozilla Public License, v. 2.0. (see the "license.txt" file for details).

The main source code is located within the "src/" folder with the following class inheritance diagram:

Socket (includes SocketException and LogFile)
|->ServerSocket
|->OperableSocket->ClientSocket

An example command to compile the source with another source file containing a main() function is included within the "compile.sh" script.

Basic example application source code for server and client applications is located within the "testapps/" folder. These are 'licensed' under CC0 (public domain).
These can be compiled by running the "servercompile.sh" and "clientcompile.sh" scripts within the root directory - the output files from these scripts will be located within the "bin/" folder.
