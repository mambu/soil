/* 
 * File:   Log.h
 * Author: marco
 */

#ifndef SOIL_LOG_H
#define SOIL_LOG_H

#include "LogWriter.h"
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
        Stream(LogWriter& writer, const std::string& level, const std::string& component);
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

    void setLevel(Level level);
    Level getLevel() const;

    Stream getStream(Level level = INFO, const std::string& component = "");

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
};

} // namespace soil

#endif // SOIL_LOG_H

