//Log class definition.
#ifndef LOG_H
#define LOG_H

#include <ctime>    //Timestamping.

#include <fstream>  //File output operations.
#include <string>   //Message handling.

    class Log
    {
        private:
            std::fstream logFile;   //Log file.
            bool isTimeStamped;     //Timestamped logs?

        public:
            Log(std::string logName = "Log.txt", bool isTimeStamped = true);    //Default Constructor - opens log.
            ~Log();                                                             //Destructor - closes log.
            void write(std::string logData);                                    //Write to log.
    };

#endif
