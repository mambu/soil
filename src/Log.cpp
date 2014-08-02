#include "soil/Log.h"
#include "soil/LogMessage.h"
#include <cassert>

namespace soil
{

Log::NullWriter Log::mNullWriter;

Log::Log()
    : mWriter(&mNullWriter)
{
}

Log::Log(LogWriter& writer)
    : mWriter(&writer)
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

void Log::setLevel(LogLevel::Level level)
{
    mLevel = level;
}

void Log::setLevel(const LogLevel& level)
{
    mLevel = level;
}

const LogLevel& Log::getLevel() const
{
    return mLevel;
}

Log::Stream Log::getStream(const LogLevel& level, const LogComponent& component)
{
    mFormat << level;
    mFormat << component;
    return Stream(isLevelEnabled(level) ? *mWriter : mNullWriter, mFormat);
}

Log::Stream Log::error(const LogComponent& component)
{
    return getStream(LogLevel::ERROR, component);
}

Log::Stream Log::warning(const LogComponent& component)
{
    return getStream(LogLevel::WARNING, component);
}

Log::Stream Log::info(const LogComponent& component)
{
    return getStream(LogLevel::Info, component);
}

Log::Stream Log::verbose(const LogComponent& component)
{
    return getStream(LogLevel::VERBOSE, component);
}

Log::Stream Log::debug(const LogComponent& component)
{
    return getStream(LogLevel::DEBUG, component);
}

bool Log::isLevelEnabled(const LogLevel& level) const
{
    return level <= mLevel;
}


Log::Stream::Stream(LogWriter& writer, LogFormat& format)
    : mWriter(writer)
    , mFormat(format)
{
}

Log::Stream::~Stream()
{
    mFormat << LogMessage(mMessage.str());
    mWriter.write(mFormat.get());
}

Log::Stream::Stream(const Log::Stream& stream)
    : mWriter(stream.mWriter)
    , mFormat(stream.mFormat)
    , mMessage(stream.mMessage.str())
{
    assert(false);
}

} // namespace soil
