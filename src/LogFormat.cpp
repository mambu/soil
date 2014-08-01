#include "soil/LogFormat.h"
#include <sstream>

namespace soil
{

LogFormat::LogFormat(const std::string& format)
{
}

std::string LogFormat::header(const std::string& level, const std::string& component)
{
    std::ostringstream os;
    os << level << ": ";
    if (!component.empty())
        os << "[" << component << "] ";
    return os.str();
}

} // namespace soil
