/* 
 * File:   FormatTest.cpp
 * Author: marco
 */

#include "soil/Format.h"
#include <gtest/gtest.h>

using namespace soil;

TEST(FormatTest, testPlainString)
{
    Format f("abcd");
    ASSERT_EQ("abcd", f.get());
    
    f.set('c', "CCC");
    ASSERT_EQ("abcd", f.get());
}

TEST(FormatTest, testSingleSpecifier)
{
    Format f("%c");
    f.set('c', "CCC");

    ASSERT_EQ("CCC", f.get());
}

TEST(FormatTest, testMixed)
{
    Format f("ab%cd");
    f.set('c', "CCC");

    ASSERT_EQ("abCCCd", f.get());
}

TEST(FormatTest, testUnsetValue)
{
    Format f("ab%c%d%%");
    f.set('c', "CCC");
    // d is missing
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

TEST(FormatTest, testFormatString)
{
    Format f("abc %s's");
    f << Format::element('s', std::string("hello"));

    ASSERT_EQ("abc hello's", f.get());
}

class FormatTestComplexElem
{
public:
    FormatTestComplexElem(int one, int two, int three)
        : mOne(one)
        , mTwo(two)
        , mThree(three)
    {}
    friend std::ostream& operator<<(std::ostream& os, const FormatTestComplexElem& e);
private:
    int mOne, mTwo, mThree;
};

std::ostream& operator<<(std::ostream& os, const FormatTestComplexElem& e)
{
    os << e.mOne << "-" << e.mTwo << "-" << e.mThree;
    return os;
}

TEST(FormatTest, testComplexElem)
{
    Format f("abc%A %C");
    f << Format::element('A', 1);
    f << Format::element('C', FormatTestComplexElem(1,2,3));

    ASSERT_EQ("abc1 1-2-3", f.get());
}
