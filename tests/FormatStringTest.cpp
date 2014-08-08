/* 
 * File:   FormatStringTest.cpp
 * Author: marco
 */

#include "soil/FormatString.h"
#include <gtest/gtest.h>

using namespace soil;

TEST(FormatStringTest, testNoSpecifier)
{
    FormatString s("abcd");
    ASSERT_EQ(1U, s.size());

    FormatString::iterator it = s.begin();
    ASSERT_FALSE(it->isSpecifier());
    ASSERT_EQ("abcd", it->getString());
    ASSERT_EQ("", it->getModifier());
}

TEST(FormatStringTest, testEscapeDelimiter)
{
    FormatString s("%%");
    ASSERT_EQ(1U, s.size());

    FormatString::iterator it = s.begin();
    ASSERT_FALSE(it->isSpecifier());
    ASSERT_EQ("%", it->getString());
    ASSERT_EQ("", it->getModifier());

    s.setFormat("abc%%def");
    ASSERT_EQ(2U, s.size());
    it = s.begin();
    ASSERT_FALSE(it->isSpecifier());
    ASSERT_EQ("abc", it->getString());
    ASSERT_EQ("", it->getModifier());
    ++it;
    ASSERT_FALSE(it->isSpecifier());
    ASSERT_EQ("%def", it->getString());
    ASSERT_EQ("", it->getModifier());
}

TEST(FormatStringTest, testSingleSpecifier)
{
    FormatString s("%l");
    ASSERT_EQ(1U, s.size());

    FormatString::iterator it = s.begin();
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('l', it->getSpecifier());
    ASSERT_EQ("", it->getModifier());
}

TEST(FormatStringTest, testMultipleSpecifiers)
{
    FormatString s("%a%A%b");
    ASSERT_EQ(3U, s.size());

    FormatString::iterator it = s.begin();
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('a', it->getSpecifier());
    ASSERT_EQ("", it->getModifier());
    ++it;
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('A', it->getSpecifier());
    ASSERT_EQ("", it->getModifier());
    ++it;
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('b', it->getSpecifier());
    ASSERT_EQ("", it->getModifier());
}

TEST(FormatStringTest, testComplexFormat)
{
    FormatString s("%l: %[_] c");
    ASSERT_EQ(3U, s.size());

    FormatString::iterator it = s.begin();
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('l', it->getSpecifier());
    ASSERT_EQ("", it->getModifier());

    ++it;
    ASSERT_FALSE(it->isSpecifier());
    ASSERT_EQ(": ", it->getString());
    ASSERT_EQ("", it->getModifier());

    ++it;
    ASSERT_TRUE(it->isSpecifier());
    ASSERT_EQ('c', it->getSpecifier());
    ASSERT_EQ("[_] ", it->getModifier());
}
