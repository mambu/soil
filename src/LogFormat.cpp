#include "soil/LogFormat.h"
#include "soil/LogLevel.h"
#include "soil/LogComponent.h"
#include "soil/LogMessage.h"
#include <sstream>

namespace soil
{

LogFormat::LogFormat(const std::string& format)
    : Format(format)
{
}

LogFormat::Map& operator<<(LogFormat::Map& format, const LogLevel& item)
{
    format.set('l', item.toString());
    return format;
}

LogFormat::Map& operator<<(LogFormat::Map& format, const LogComponent& item)
{
    format.set('c', item);
    return format;
}

LogFormat::Map& operator<<(LogFormat::Map& format, const LogMessage& item)
{
    format.set('m', item);
    return format;
}

} // namespace soil
