/*
 * File: LogLevel.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOGLEVEL_H
#define SOIL_LOGLEVEL_H

#include <string>

namespace soil
{

class LogLevel
{
private:
    enum Level
    {
        ERROR,
        WARNING,
        INFO,
        VERBOSE,
        DEBUG
    };

private:
    LogLevel(Level l)
        : mLevel(l)
    {}

public:
    bool operator==(const LogLevel& l) const;
    bool operator!=(const LogLevel& l) const;
    bool operator<=(const LogLevel& l) const;
    bool operator<=(Level l) const;

    operator Level() { return mLevel; }
    const std::string& toString() const;

    static const LogLevel Error;
    static const LogLevel Warning;
    static const LogLevel Info;
    static const LogLevel Verbose;
    static const LogLevel Debug;

private:
    Level mLevel;
};

} // namespace soil

#endif // SOIL_LOGLEVEL_H

