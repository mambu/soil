/* 
 * File: Log.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOG_H
#define SOIL_LOG_H

#include "soil/LogWriter.h"
#include "soil/LogFormat.h"
#include <string>
#include <sstream>

namespace soil
{

class Log
{
public:
    enum Level
    {
        ERROR,
        WARNING,
        INFO,
        VERBOSE,
        DEBUG
    };

private:
    class Stream
    {
    public:
        Stream(LogWriter& writer, const std::string& header);
        Stream(const Stream& stream);
        virtual ~Stream();

        inline Stream& operator<<(std::ostream& (*f)(std::ostream&))
        {
            f(mMessage);
            return *this;
        }

        template <class T>
        inline Stream& operator<<(const T& value)
        {    
            mMessage << value;
            return *this;
        }

    private:
        LogWriter& mWriter;
        std::ostringstream mMessage;

    private:
        friend class Log;        
   };

   class NullWriter : public LogWriter
   {
      virtual void write(const std::string& message) {}
   };

public:
    Log();
    Log(LogWriter& writer);

    void setWriter(LogWriter& writer);
    void setFormat(const std::string& format);

    void setLevel(Level level);
    Level getLevel() const;

    Stream getStream(Level level, const std::string& component = "");

    Stream error(const std::string& component = "");
    Stream warning(const std::string& component = "");
    Stream info(const std::string& component = "");
    Stream verbose(const std::string& component = "");
    Stream debug(const std::string& component = "");

private:
    bool isLevelEnabled(Level level) const;
    static const std::string& levelToString(Level level);

private:
    static NullWriter mNullWriter;
    LogWriter* mWriter;
    Level mLevel;
    LogFormat mFormat;
};

} // namespace soil

#endif // SOIL_LOG_H

