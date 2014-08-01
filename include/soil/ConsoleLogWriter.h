/* 
 * File:   ConsoleLogWriter.h
 * Author: marco
 *
 * Created on 01 August 2014, 13:10
 */

#ifndef SOIL_CONSOLELOGWRITER_H
#define SOIL_CONSOLELOGWRITER_H

#include "soil/LogWriter.h"
#include <iostream>

namespace soil
{

class ConsoleLogWriter : public LogWriter
{
public:
    inline void write(const std::string& message)
    {
        std::cout << message;
    }
};

} // namespace soil

#endif // SOIL_CONSOLELOGWRITER_H

