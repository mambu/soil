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
public:
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

    typedef std::map<char, std::string> Values;
public:
    class Map : public Values
    {
    public:
        inline void set(char key, const std::string& value)
        {
            (*this)[key] = value;
        }

    private:
        template <class T>
        friend Map& operator<<(Map& format, const Format::Element<T>& item);
    };

public:
    Format(const std::string& format);
    void setFormat(const std::string& format);

    std::string get(const Map& map);

    template <class T>
    static Element<T> element(char c, const T& elem)
    {
        return Element<T>(c, elem);
    }

private:
    FormatString mFormat;
};

template <class T>
Format::Map& operator<<(Format::Map& formatMap, const Format::Element<T>& item)
{
    std::ostringstream os;
    os << item.getElem();
    formatMap.set(item.getKey(), os.str());
    return formatMap;
}

template <>
Format::Map& operator<< <std::string>(Format::Map& formatMap, const Format::Element<std::string>& item);

} // namespace soil

#endif // SOIL_FORMAT_H

