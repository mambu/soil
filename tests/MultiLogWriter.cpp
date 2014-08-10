/* 
 * File:   MultiLogWriterTest.cpp
 * Author: Marco Ambu
 *
 * Created on 10-Aug-2014, 10:58:21
 */

#include "soil/Log.h"
#include "soil/MultiLogWriter.h"
#include <gtest/gtest.h>

using namespace soil;

namespace
{
class TestLogWriter : public LogWriter
{
public:
    virtual void write(const std::string& s)
    {
       mMessage = s;
    }

    std::string mMessage;
};
}

TEST(MultLogWriterTest, test1)
{
    TestLogWriter logWriter1;
    TestLogWriter logWriter2;
    MultiLogWriter multiWriter;
    multiWriter.add(logWriter1).add(logWriter2);

    Log log(multiWriter);
    std::string msg1 = "Message #1";
    log.info() << msg1;

    std::string expectedMsg1 = "INFO:  ";
    expectedMsg1 += msg1;
    ASSERT_EQ(expectedMsg1, logWriter1.mMessage);
    ASSERT_EQ(expectedMsg1, logWriter2.mMessage);

    std::string msg2 = "Message #2++";
    log.info() << msg2;

    std::string expectedMsg2 = "INFO:  ";
    expectedMsg2 += msg2;
    ASSERT_EQ(expectedMsg2, logWriter1.mMessage);
    ASSERT_EQ(expectedMsg2, logWriter2.mMessage);
}
