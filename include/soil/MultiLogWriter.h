/* 
 * File: MultiLogWriter.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_MULTILOGWRITER_H
#define	SOIL_MULTILOGWRITER_H

#include "soil/LogWriter.h"
#include <vector>

namespace soil
{

class MultiLogWriter : public LogWriter
{
public:
    MultiLogWriter& add(LogWriter& writer);
    MultiLogWriter& remove(LogWriter& writer);

    virtual void write(const LogFormat::Map& formatMap);

private:
    virtual void write(const std::string& message);
    
private:
    std::vector<LogWriter*> mItems;
};

} // namespace soil

#endif // SOIL_MULTILOGWRITER_H

