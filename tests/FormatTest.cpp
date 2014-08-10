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
    ASSERT_EQ("abcd", f.get(Format::Map()));

    Format::Map m;
    m.set('c', "CCC");
    ASSERT_EQ("abcd", f.get(m));
}

TEST(FormatTest, testSingleSpecifier)
{
    Format f("%c");
    Format::Map m;
    m.set('c', "CCC");

    ASSERT_EQ("CCC", f.get(m));
}

TEST(FormatTest, testMixed)
{
    Format f("ab%cd");
    Format::Map m;
    m.set('c', "CCC");

    ASSERT_EQ("abCCCd", f.get(m));
}

TEST(FormatTest, testUnsetValue)
{
    Format f("ab%c%d%%");
    Format::Map m;
    m.set('c', "CCC");
    // d is missing
    ASSERT_EQ("abCCC%", f.get(m));
}

TEST(FormatTest, testSetMultipleTimes)
{
    Format f("ab%cd");
    Format::Map m;
    m.set('c', "CCC");
    m.set('c', "CCCCC");

    ASSERT_EQ("abCCCCCd", f.get(m));
}

TEST(FormatTest, testFormatElem)
{
    Format f("abc%d%f");
    Format::Map m;
    m << Format::element('d', 1);
    m << Format::element('f', 1.1);

    ASSERT_EQ("abc11.1", f.get(m));
}

TEST(FormatTest, testFormatString)
{
    Format f("abc %s's");
    Format::Map m;
    m << Format::element('s', std::string("hello"));

    ASSERT_EQ("abc hello's", f.get(m));
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
    Format::Map m;
    m << Format::element('A', 1);
    m << Format::element('C', FormatTestComplexElem(1,2,3));

    ASSERT_EQ("abc1 1-2-3", f.get(m));
}
