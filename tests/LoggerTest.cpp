/* 
 * File:   LoggerTest.cpp
 * Author: marco
 */

#include "soil/Logger.h"
#include <gtest/gtest.h>

using namespace soil;

TEST(LoggerTest, test)
{
    Log& log = Logger::get();
    ASSERT_EQ(Log::INFO, log.getLevel());
}
