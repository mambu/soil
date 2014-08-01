/* 
 * File: Logger.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_LOGGER_H
#define SOIL_LOGGER_H

#include "soil/Log.h"
#include "soil/Singleton.h"

namespace soil
{

class Logger : public Singleton<Log>
{
protected:
    Logger() {}

private:
    friend class Singleton<Log>;
};

} // namespace soil

#endif // SOIL_LOGGER_H

