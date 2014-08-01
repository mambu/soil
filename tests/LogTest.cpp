/* 
 * File:   LogTest.cpp
 * Author: Marco Ambu
 *
 * Created on 16-Jun-2012, 10:58:21
 */

#include "soil/Log.h"
#include <gtest/gtest.h>

using namespace soil;

class TestLogWriter : public LogWriter
{
public:
    virtual void write(const std::string& s)
    {
       mMessage = s;
    }

    std::string mMessage;
};

TEST(LogTest, test1)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    ASSERT_EQ(Log::INFO, log.getLevel());

    log.setLevel(Log::DEBUG);
    ASSERT_EQ(Log::DEBUG, log.getLevel());
}

TEST(LogTest, test2)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.info() << "hello" << " " << "world";

    ASSERT_EQ("INFO: hello world", logWriter.mMessage);
}

TEST(LogTest, test3)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.verbose() << "hello";

    ASSERT_EQ("", logWriter.mMessage);
}

TEST(LogTest, test4)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.setLevel(Log::VERBOSE);
    log.verbose() << "hello";

    ASSERT_EQ("VERBOSE: hello", logWriter.mMessage);
}
