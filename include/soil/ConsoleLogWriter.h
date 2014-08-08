/* 
 * File:   ConsoleLogWriter.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_CONSOLELOGWRITER_H
#define SOIL_CONSOLELOGWRITER_H

#include "soil/LogWriter.h"
#include <string>
#include <iostream>

namespace soil
{

class ConsoleLogWriter : public LogWriter
{
public:
    void write(const std::string& message);
};

inline void ConsoleLogWriter::write(const std::string& message)
{
    std::cout << message;
}

} // namespace soil

#endif // SOIL_CONSOLELOGWRITER_H

