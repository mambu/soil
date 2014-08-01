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

namespace soil
{

class LogFormat
{
public:
    LogFormat(const std::string& format = "%l: %[_] c");

    void setFormat(const std::string& format);

    std::string header(const std::string& level, const std::string& component);

private:
    FormatString mFormat;
};

} // namespace soil

#endif // SOIL_LOGFORMAT_H

