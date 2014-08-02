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
    ASSERT_EQ(LogLevel::Info, log.getLevel());

    log.setLevel(LogLevel::Debug);
    ASSERT_EQ(LogLevel::Debug, log.getLevel());
}

TEST(LogTest, test2)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.info() << "hello" << " " << "world";

    ASSERT_EQ("INFO:  hello world", logWriter.mMessage);
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
    log.setLevel(LogLevel::Verbose);
    log.verbose() << "hello";

    ASSERT_EQ("VERBOSE:  hello", logWriter.mMessage);
}

TEST(LogTest, testFormat)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.setFormat("%l - %c: %m");
    log.info("comp") << "hello";

    ASSERT_EQ("INFO - comp: hello", logWriter.mMessage);
}

TEST(LogTest, testFormatNoMessage)
{
    TestLogWriter logWriter;
    Log log(logWriter);
    log.setFormat("%l - (%c)");
    log.info("comp") << "hello";

    ASSERT_EQ("INFO - (comp)", logWriter.mMessage);
}
