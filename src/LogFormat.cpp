#include "soil/LogFormat.h"
#include "soil/LogLevel.h"
#include "soil/LogComponent.h"
#include <sstream>

namespace soil
{

LogFormat::LogFormat(const std::string& format)
    : mFormat(format)
{
}

void LogFormat::setFormat(const std::string& format)
{
    mFormat.setFormat(format);
}

std::string LogFormat::get()
{
    std::ostringstream os;
    for (FormatString::iterator it = mFormat.begin();
            it != mFormat.end();
            ++it)
    {
        if (it->isSpecifier())
        {
            Values::const_iterator i = mValues.find(it->getSpecifier());
            if (i != mValues.end())
            {
                os << i->second;
            }
            else
            {
                os << it->getSpecifier();
            }
//            switch (it->getSpecifier())
//            {
//            case 'l':
//                os << level;
//                break;
//            case 'c':
//                if (!component.empty())
//                {
//                    const std::string& mod = it->getModifier();
//                    if (mod.empty())
//                    {
//                        os << component;
//                    }
//                    else
//                    {
//                        for (std::string::const_iterator i = mod.begin();
//                             i != mod.end();
//                             ++i)
//                        {
//                            if (*i == '_') os << component;
//                            else           os << *i;
//                        }
//                    }
//                }
//                break;
//            default:
//                os << it->getSpecifier();
//                break;
//            }
        }
        else
        {
            os << it->getString();
        }
    }
    mValues.clear();
    return os.str();
}

template <>
LogFormat& operator<<(LogFormat& format, const LogLevel& item)
{
    format.mValues['l'] = item.toString();
    return format;
}

template <>
LogFormat& operator<<(LogFormat& format, const LogComponent& item)
{
    format.mValues['c'] = item;
    return format;
}

template <>
LogFormat& operator<<(LogFormat& format, const std::string& item)
{
    format.mValues['m'] = item;
    return format;
}

} // namespace soil
