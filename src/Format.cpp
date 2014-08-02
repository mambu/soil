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

void Format::set(char key, const std::string& value)
{
    mValues[key] = value;
}

std::string Format::get()
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
//            else
//            {
//                os << it->getSpecifier();
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

} // namespace soil
