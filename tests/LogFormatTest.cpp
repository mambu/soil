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
    LogFormat f;
    f << LogLevel::Verbose;

    ASSERT_EQ("VERBOSE:  ", f.get());
}

TEST(LogFormatTest, testLogComponent)
{
    LogFormat f;
    f << LogComponent("component1");
    f << LogLevel::Warning;

    ASSERT_EQ("WARNING: component1 ", f.get());
}

TEST(LogFormatTest, testLogMessage)
{
    LogFormat f;
    f << LogMessage("msg #1");
    f << LogComponent("component1");
    f << LogLevel::Warning;

    ASSERT_EQ("WARNING: component1 msg #1", f.get());
}

TEST(LogFormatTest, testCustomFormat)
{
    LogFormat f("(%l) %c - [%m]");
    f << LogMessage("msg #1");
    f << LogComponent("component1");
    f << LogLevel::Warning;

    ASSERT_EQ("(WARNING) component1 - [msg #1]", f.get());
}
