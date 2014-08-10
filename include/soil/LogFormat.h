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

#include "soil/Format.h"

namespace soil
{

class LogLevel;
class LogComponent;
class LogMessage;

class LogFormat : public Format
{
public:
    LogFormat(const std::string& format = "%l: %c %m");
};

LogFormat::Map& operator<<(LogFormat::Map& format, const LogLevel& item);
LogFormat::Map& operator<<(LogFormat::Map& format, const LogComponent& item);
LogFormat::Map& operator<<(LogFormat::Map& format, const LogMessage& item);

} // namespace soil

#endif // SOIL_LOGFORMAT_H

