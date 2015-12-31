//Log File class definition.
#ifndef LOGFILE_H
#define LOGFILE_H

#include <ctime>    //Timestamping.

#include <fstream>  //File output operations.
#include <string>   //Message handling.

    class LogFile   //File logging operations.
    {
        private:
            std::fstream file;   //Log file.
            bool isTimeStamped;     //Timestamped logs?

        public:
            LogFile(std::string logName = "Log.txt", bool isTimeStamped = true);    //Default Constructor - opens log.
            ~LogFile();                                                             //Destructor - closes log.
            void write(std::string logData);                                        //Write to log.
    };

#endif
