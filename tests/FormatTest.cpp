/* 
 * File:   FormatTest.cpp
 * Author: marco
 */

#include "soil/Format.h"
#include <gtest/gtest.h>

using namespace soil;

TEST(FormatTest, test)
{
    Format f("ab%cd");
    f.set('c', "CCC");

    ASSERT_EQ("abCCCd", f.get());
}

TEST(FormatTest, testUnsetValue)
{
    Format f("ab%c%d%%");
    f.set('c', "CCC");

    ASSERT_EQ("abCCC%", f.get());
}

TEST(FormatTest, testSetMultipleTimes)
{
    Format f("ab%cd");
    f.set('c', "CCC");
    f.set('c', "CCCCC");

    ASSERT_EQ("abCCCCCd", f.get());
}

TEST(FormatTest, testFormatElem)
{
    Format f("abc%d%f");
    f << Format::element('d', 1);
    f << Format::element('f', 1.1);

    ASSERT_EQ("abc11.1", f.get());
}
