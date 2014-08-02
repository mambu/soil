/*
 * LogMessage.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOGMESSAGE_H
#define SOIL_LOGMESSAGE_H

#include <string>

namespace soil
{

class LogMessage : public std::string
{
public:
    LogMessage(const char* comp = "")
        : std::string(comp)
    {}
    LogMessage(const std::string& comp)
        : std::string(comp)
    {}
};

} // namespace soil

#endif // SOIL_LOGMESSAGE_H

