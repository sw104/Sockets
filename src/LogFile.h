/*
 * Copyright 2016 Sam White
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Log File class definition.
#ifndef LOGFILE_H
#define LOGFILE_H

#include <ctime>    //Timestamping.
#include <iomanip>  //Timestamping - put_time().

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
