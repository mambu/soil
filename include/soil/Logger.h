/* 
 * File:   Logger.h
 * Author: marco
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

