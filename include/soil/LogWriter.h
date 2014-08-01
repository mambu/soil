/* 
 * File:   LogWriter.h
 * Author: marco
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

class LogMultiWriter : public LogWriter
{
public:
    void add(LogWriter& writer);
    void remove(LogWriter& writer);

    void write(const std::string& message);
};

} // namespace soil

#endif // SOIL_LOGWRITER_H
