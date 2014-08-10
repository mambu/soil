/* 
 * File:   LogFormatTest.cpp
 * Author: marco
 */

#include "soil/LogFormat.h"
#include "soil/LogLevel.h"
#include "soil/LogComponent.h"
#include "soil/LogMessage.h"
#include <gtest/gtest.h>

using namespace soil;

TEST(LogFormatTest, testLogLevel)
{
    LogFormat::Map m;
    m << LogLevel::Verbose;

    LogFormat f;
    ASSERT_EQ("VERBOSE:  ", f.get(m));
}

TEST(LogFormatTest, testLogComponent)
{
    LogFormat::Map m;
    m << LogComponent("component1");
    m << LogLevel::Warning;

    LogFormat f;
    ASSERT_EQ("WARNING: component1 ", f.get(m));
}

TEST(LogFormatTest, testLogMessage)
{
    LogFormat::Map m;
    m << LogMessage("msg #1");
    m << LogComponent("component1");
    m << LogLevel::Warning;

    LogFormat f;
    ASSERT_EQ("WARNING: component1 msg #1", f.get(m));
}

TEST(LogFormatTest, testCustomFormat)
{
    LogFormat::Map m;
    m << LogMessage("msg #1");
    m << LogComponent("component1");
    m << LogLevel::Warning;

    LogFormat f("(%l) %c - [%m]");

    ASSERT_EQ("(WARNING) component1 - [msg #1]", f.get(m));
}
