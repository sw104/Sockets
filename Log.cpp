//Log class implementation.

#include "Log.h"

//Public methods:

Log::Log(std::string logName, bool isTimeStamped)
{	
	this->isTimeStamped = isTimeStamped;
	logFile.open(logName, std::fstream::out | std::fstream::app);   //Append any existing file.
}

Log::~Log()
{
    logFile.close();
}

void Log::write(std::string logData)
{
    if (isTimeStamped)
        logFile << time(NULL) << ": " << logData << std::endl;  //Write timestamped entry.	
    else
        logFile << logData << std::endl;
}
