/*
 * Format.h
 *
 * Copyright (c) 2014 Marco Ambu
 */

#ifndef SOIL_FORMAT_H
#define SOIL_FORMAT_H

#include "soil/FormatString.h"
#include <map>
#include <sstream>

namespace soil
{

class Format
{
private:
    template <class T>
    class Element
    {
    public:
        Element(char c, const T& elem)
            : mKey(c)
            , mElem(elem)
        {}

        inline char getKey() const { return mKey; }
        inline const T& getElem() const { return mElem; }

    private:
        char mKey;
        const T& mElem;
    };

public:
    Format(const std::string& format);
    void setFormat(const std::string& format);

    void set(char key, const std::string& value);

    std::string get();

    template <class T>
    static Element<T> element(char c, const T& elem)
    {
        return Element<T>(c, elem);
    }

protected:
    FormatString mFormat;
    typedef std::map<char, std::string> Values;
    Values mValues;
};

template <class T>
Format& operator<<(Format& format, const Format::Element<T>& item)
{
    std::ostringstream os;
    os << item.getElem();
    format.set(item.getKey(), os.str());
    return format;
}

} // namespace soil

#endif // SOIL_FORMAT_H

