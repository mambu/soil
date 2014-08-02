/*
 * LogFormat.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOGFORMAT_H
#define SOIL_LOGFORMAT_H

#include "soil/FormatString.h"
#include <map>

namespace soil
{

class LogFormat
{
public:
    LogFormat(const std::string& format = "%l: %c %m");

    void setFormat(const std::string& format);

    std::string get();

private:
    FormatString mFormat;
    typedef std::map<char, std::string> Values;
    Values mValues;

private:
    template <class T>
    friend LogFormat& operator<<(LogFormat& format, const T& item);
};

} // namespace soil

#endif // SOIL_LOGFORMAT_H

