/*
 * File: LogComponent.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOGCOMPONENT_H
#define SOIL_LOGCOMPONENT_H

#include <string>

namespace soil
{

class LogComponent : public std::string
{
public:
    LogComponent(const char* comp)
        : std::string(comp)
    {}
    LogComponent(const std::string& comp = "")
        : std::string(comp)
    {}
};

}

#endif // SOIL_LOGCOMPONENT_H

