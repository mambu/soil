#include "soil/Log.h"
#include "soil/LogFormat.h"
#include <cassert>

namespace soil
{

Log::NullWriter Log::mNullWriter;

Log::Log()
    : mWriter(&mNullWriter)
    , mLevel(Log::INFO)
{
}

Log::Log(LogWriter& writer)
    : mWriter(&writer)
    , mLevel(Log::INFO)
{
}

void Log::setWriter(LogWriter& writer)
{
    mWriter = &writer;
}

void Log::setFormat(const std::string& format)
{
    mFormat.setFormat(format);
}

void Log::setLevel(Log::Level level)
{
    mLevel = level;
}

Log::Level Log::getLevel() const
{
    return mLevel;
}

Log::Stream Log::getStream(Log::Level level, const std::string& component)
{
    return Stream(isLevelEnabled(level) ? *mWriter : mNullWriter, mFormat.header(levelToString(level), component));
}

Log::Stream Log::error(const std::string& component)
{
    return getStream(ERROR, component);
}

Log::Stream Log::warning(const std::string& component)
{
    return getStream(WARNING, component);
}

Log::Stream Log::info(const std::string& component)
{
    return getStream(INFO, component);
}

Log::Stream Log::verbose(const std::string& component)
{
    return getStream(VERBOSE, component);
}

Log::Stream Log::debug(const std::string& component)
{
    return getStream(DEBUG, component);
}

bool Log::isLevelEnabled(Log::Level level) const
{
    return level <= mLevel; 
}

const std::string& Log::levelToString(Level level)
{
    switch (level)
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


Log::Stream::Stream(LogWriter& writer, const std::string& header)
    : mWriter(writer)
{
    mMessage << header;
}

Log::Stream::~Stream()
{
    mWriter.write(mMessage.str());
}

Log::Stream::Stream(const Log::Stream& stream)
    : mWriter(stream.mWriter)
    , mMessage(stream.mMessage.str())
{
    assert(false);
}

} // namespace soil
