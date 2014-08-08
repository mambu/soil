/*
 * FormatString.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_FORMATSTRING_H
#define SOIL_FORMATSTRING_H

#include <string>
#include <vector>

namespace soil
{

class FormatString
{
private:
    class Format
    {
    public:
        Format(char format, const std::string& modifier = "");
        Format(const std::string& format);
        char getSpecifier() const { return mString[0]; }
        bool isSpecifier() const { return mSpecifier; }
        const std::string& getString() const { return mString; }
        const std::string& getModifier() const { return mModifier; }

    private:
        std::string mString;
        bool mSpecifier;
        std::string mModifier;
    };

public:
    typedef std::vector<Format> FormatItems;
    typedef FormatItems::const_iterator iterator;
    inline iterator begin() const { return mFormatItems.begin(); }
    inline iterator end() const { return mFormatItems.end(); }
    inline std::size_t size() const { return mFormatItems.size(); }

public:
    FormatString(const std::string& format = "");

    void setFormat(const std::string& format);

private:
    FormatItems mFormatItems;
};

} // namespace soil

#endif // SOIL_FORMATSTRING_H

