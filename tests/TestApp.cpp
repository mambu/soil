/* 
 * File:   TestApp.cpp
 * Author: marco
 */

#include "soil/Logger.h"
#include "soil/ConsoleLogWriter.h"
#include "soil/FileLogWriter.h"
#include "soil/MultiLogWriter.h"
#include <iostream>

using namespace soil;

int main(int argc, char** argv)
{
    ConsoleLogWriter consoleWriter;
    FileLogWriter fileWriter("app.log");
    MultiLogWriter logWriter;
    logWriter.add(consoleWriter).add(fileWriter);
    Logger::get().setWriter(logWriter);
    Logger::get().info("App") << "Started" << std::endl;
    
    Logger::get().info("App") << "Stopped" << std::endl;

    return 0;
}

