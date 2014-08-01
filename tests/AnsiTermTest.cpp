/* 
 * File:   AnsiTermTest.cpp
 * Author: Marco Ambu
 *
 * Created on 26-Jun-2012, 10:57:33
 */

#include "soil/AnsiTerm.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace soil;

TEST(AnsiTermTest, testReset)
{
    ASSERT_EQ("\x1B[0m", AnsiTerm::reset());
}

TEST(AnsiTermTest, testFormat)
{
    // no format
    ASSERT_EQ(AnsiTerm::reset(), AnsiTerm::format(AnsiTerm::NO_ATTR, AnsiTerm::NO_COLOUR, AnsiTerm::NO_COLOUR));
    // only attr
    ASSERT_EQ("\x1B[1m", AnsiTerm::format(AnsiTerm::BRIGHT, AnsiTerm::NO_COLOUR, AnsiTerm::NO_COLOUR));
    // only fg
    ASSERT_EQ("\x1B[30m", AnsiTerm::format(AnsiTerm::NO_ATTR, AnsiTerm::BLACK, AnsiTerm::NO_COLOUR));
    // only bg
    ASSERT_EQ("\x1B[41m", AnsiTerm::format(AnsiTerm::NO_ATTR, AnsiTerm::NO_COLOUR, AnsiTerm::RED));
    // only colours
    ASSERT_EQ("\x1B[33;44m", AnsiTerm::format(AnsiTerm::NO_ATTR, AnsiTerm::YELLOW, AnsiTerm::BLUE));
    // only attr and fg
    ASSERT_EQ("\x1B[4;33m", AnsiTerm::format(AnsiTerm::BLINK, AnsiTerm::YELLOW, AnsiTerm::NO_COLOUR));
    // only attr and bg
    ASSERT_EQ("\x1B[4;40m", AnsiTerm::format(AnsiTerm::BLINK, AnsiTerm::NO_COLOUR, AnsiTerm::BLACK));

    ASSERT_EQ("\x1B[1;37;40m", AnsiTerm::format(AnsiTerm::BRIGHT, AnsiTerm::WHITE, AnsiTerm::BLACK));
}

TEST(AnsiTermTest, testStreamManipulatores)
{
    std::ostringstream os;
    os << AnsiTerm::reset;
    ASSERT_EQ("\x1B[0m", os.str());

    os << std::dec << AnsiTerm::underline
            << "Hello underline"
            << AnsiTerm::bright << " + bright"
            << AnsiTerm::reverse << " + reverse"
            << AnsiTerm::reset << " normal";
    ASSERT_EQ("\x1B[0m\x1B[3mHello underline\x1B[1m + bright\x1B[7m + reverse\x1B[0m normal", os.str());
//    std::cout << os.str() << std::endl;
}
