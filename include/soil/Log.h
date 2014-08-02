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
#include "soil/LogLevel.h"
#include "soil/LogComponent.h"
#include <string>
#include <sstream>

namespace soil
{

class Log
{
private:
    class Stream
    {
    public:
        Stream(LogWriter& writer, LogFormat& format);
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
        LogFormat& mFormat;
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

    void setLevel(const LogLevel& level);
    const LogLevel& getLevel() const;

    Stream getStream(const LogLevel& level, const LogComponent& component);

    Stream error(const LogComponent& component = LogComponent());
    Stream warning(const LogComponent& component = LogComponent());
    Stream info(const LogComponent& component = LogComponent());
    Stream verbose(const LogComponent& component = LogComponent());
    Stream debug(const LogComponent& component = LogComponent());

private:
    bool isLevelEnabled(const LogLevel& level) const;

private:
    static NullWriter mNullWriter;
    LogWriter* mWriter;
    LogLevel mLevel;
    LogFormat mFormat;
};

} // namespace soil

#endif // SOIL_LOG_H

