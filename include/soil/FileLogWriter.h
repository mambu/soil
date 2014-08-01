/* 
 * File: FileLogWriter.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_FILELOGWRITER_H
#define SOIL_FILELOGWRITER_H

#include "soil/LogWriter.h"
#include <fstream>

namespace soil
{

class FileLogWriter : public LogWriter
{
public:
    FileLogWriter(const std::string& filename, bool append = false);

    inline void write(const std::string& message)
    {
        mFile << message;
    }

private:
    std::ofstream mFile;
};

} // namespace soil

#endif // SOIL_FILELOGWRITER_H

