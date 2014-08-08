#include "soil/LogLevel.h"
#include <string>

namespace soil
{

const LogLevel LogLevel::Error = LogLevel(LogLevel::ERROR);
const LogLevel LogLevel::Warning = LogLevel(LogLevel::WARNING);
const LogLevel LogLevel::Info = LogLevel(LogLevel::INFO);
const LogLevel LogLevel::Verbose = LogLevel(LogLevel::VERBOSE);
const LogLevel LogLevel::Debug = LogLevel(LogLevel::DEBUG);

bool LogLevel::operator==(const LogLevel& l) const
{
    return mLevel == l.mLevel;
}
bool LogLevel::operator!=(const LogLevel& l) const
{
    return mLevel != l.mLevel;
}

bool LogLevel::operator<=(const LogLevel& l) const
{
    return mLevel <= l.mLevel;
}

bool LogLevel::operator<=(LogLevel::Level l) const
{
    return mLevel <= l;
}

const std::string& LogLevel::toString() const
{
    switch (mLevel)
    {
    case ERROR:
    {
        static std::string error = "ERROR";
        return error;
    }
    case WARNING:
    {
        static std::string warning = "WARNING";
        return warning;
    }
    case VERBOSE:
    {
        static std::string verbose = "VERBOSE";
        return verbose;
    }
    case DEBUG:
    {
        static std::string debug = "DEBUG";
        return debug;
    }
    case INFO:
    default:
    {
        static std::string info = "INFO";
        return info;
    }
    }
}

} // namespace soil
