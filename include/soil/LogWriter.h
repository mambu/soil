/*
 * File: LogWriter.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
*/

#ifndef SOIL_LOGWRITER_H
#define SOIL_LOGWRITER_H

#include <string>

namespace soil
{

class LogWriter
{
public:
    virtual ~LogWriter() {}

    virtual void write(const std::string& message) = 0;
};

} // namespace soil

#endif // SOIL_LOGWRITER_H
