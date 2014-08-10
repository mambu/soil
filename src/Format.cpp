#include "soil/Format.h"

namespace soil
{

Format::Format(const std::string& format)
    : mFormat(format)
{
}

void Format::setFormat(const std::string& format)
{
    mFormat.setFormat(format);
}

std::string Format::get(const Format::Map& map)
{
    std::ostringstream os;
    for (FormatString::iterator it = mFormat.begin();
            it != mFormat.end();
            ++it)
    {
        if (it->isSpecifier())
        {
            Values::const_iterator i = map.find(it->getSpecifier());
            if (i != map.end())
            {
                os << i->second;
            }
        }
        else
        {
            os << it->getString();
        }
    }
    return os.str();
}

template <>
Format::Map& operator<< <std::string>(Format::Map& formatMap, const Format::Element<std::string>& item)
{
    formatMap.set(item.getKey(), item.getElem());
    return formatMap;
}

} // namespace soil
