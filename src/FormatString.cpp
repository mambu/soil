#include "soil/FormatString.h"

namespace soil
{

FormatString::Format::Format(char format, const std::string& modifier)
    : mString(1, format)
    , mSpecifier(true)
    , mModifier(modifier)
{
}

FormatString::Format::Format(const std::string& format)
    : mString(format)
    , mSpecifier(false)
{
}


FormatString::FormatString(const std::string& format)
{
    setFormat(format);
}

void FormatString::setFormat(const std::string& format)
{
    mFormatItems.clear();
    if (format.empty())
        return;

    std::string tmp;
    bool specifier = false;
    for (std::string::const_iterator it = format.begin();
        it != format.end();
        ++it)
    {
        if (*it == '%')
        {
            if (specifier) // escape %
            {
                tmp.push_back('%');
                specifier = false;
                continue;
            }
            if (!tmp.empty())
            {
                mFormatItems.push_back(Format(tmp));
                tmp.clear();
            }
            specifier = true;
            continue;
        }
        
        if (specifier)
        {
            if (!std::isalpha(*it))
            {
                tmp.push_back(*it);
                continue;
            }
            mFormatItems.push_back(Format(*it, tmp));
            tmp.clear();
            specifier = false;
        }
        else
        {
            tmp.push_back(*it);
        }
    }
    if (!tmp.empty())
    {
        mFormatItems.push_back(Format(tmp));
    }
}

} // namespace soil

