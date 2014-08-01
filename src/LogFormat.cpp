#include "soil/LogFormat.h"
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

std::string LogFormat::header(const std::string& level, const std::string& component)
{
    std::ostringstream os;
    for (FormatString::iterator it = mFormat.begin();
            it != mFormat.end();
            ++it)
    {
        if (it->isSpecifier())
        {
            switch (it->getSpecifier())
            {
            case 'l':
                os << level;
                break;
            case 'c':
                if (!component.empty())
                {
                    const std::string& mod = it->getModifier();
                    if (mod.empty())
                    {
                        os << component;
                    }
                    else
                    {
                        for (std::string::const_iterator i = mod.begin();
                             i != mod.end();
                             ++i)
                        {
                            if (*i == '_') os << component;
                            else           os << *i;
                        }
                    }
                }
                break;
            default:
                os << it->getSpecifier();
                break;
            }
        }
        else
        {
            os << it->getString();
        }
    }
    return os.str();
}

} // namespace soil
