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
    {
        std::time_t t = std::time(NULL);      
        file << std::put_time(std::gmtime(&t), "%c %Z") << ": " << logData << std::endl;  //Write timestamped entry.	
    }
    else
        file << logData << std::endl;
}
