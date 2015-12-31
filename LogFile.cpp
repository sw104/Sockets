//Log File class implementation.

#include "LogFile.h"

//Public methods:

LogFile::LogFile(std::string logName, bool isTimeStamped)
{	
	this->isTimeStamped = isTimeStamped;
	file.open(logName, std::fstream::out | std::fstream::app);   //Append any existing file.
}

LogFile::~LogFile()
{
    file.close();
}

void LogFile::write(std::string logData)
{
    if (isTimeStamped)
        file << time(NULL) << ": " << logData << std::endl;  //Write timestamped entry.	
    else
        file << logData << std::endl;
}
