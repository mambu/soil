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
    ASSERT_EQ(AnsiTerm::reset(), AnsiTerm::format(AnsiTerm::Style::NONE,
                                                  AnsiTerm::Colour::NONE,
                                                  AnsiTerm::Colour::NONE));
    // only attr
    ASSERT_EQ("\x1B[1m", AnsiTerm::format(AnsiTerm::Style::FONT_BRIGHT,
                                          AnsiTerm::Colour::NONE,
                                          AnsiTerm::Colour::NONE));
    // only fg
    ASSERT_EQ("\x1B[30m", AnsiTerm::format(AnsiTerm::Style::NONE,
                                           AnsiTerm::Colour::BLACK,
                                           AnsiTerm::Colour::NONE));
    // only bg
    ASSERT_EQ("\x1B[41m", AnsiTerm::format(AnsiTerm::Style::NONE,
                                           AnsiTerm::Colour::NONE,
                                           AnsiTerm::Colour::RED));
    // only colours
    ASSERT_EQ("\x1B[33;44m", AnsiTerm::format(AnsiTerm::Style::NONE,
                                              AnsiTerm::Colour::YELLOW,
                                              AnsiTerm::Colour::BLUE));
    // only attr and fg
    ASSERT_EQ("\x1B[5;33m", AnsiTerm::format(AnsiTerm::Style::BLINK,
                                             AnsiTerm::Colour::YELLOW,
                                             AnsiTerm::Colour::NONE));
    // only attr and bg
    ASSERT_EQ("\x1B[5;40m", AnsiTerm::format(AnsiTerm::Style::BLINK,
                                             AnsiTerm::Colour::NONE,
                                             AnsiTerm::Colour::BLACK));

    ASSERT_EQ("\x1B[2;37;40m", AnsiTerm::format(AnsiTerm::Style::FONT_DIM,
                                                AnsiTerm::Colour::WHITE,
                                                AnsiTerm::Colour::BLACK));
}

TEST(AnsiTermTest, testNoColour)
{
    ASSERT_EQ("", AnsiTerm::fg(AnsiTerm::Colour::NONE));
    ASSERT_EQ("", AnsiTerm::bg(AnsiTerm::Colour::NONE));
}

TEST(AnsiTermTest, testStreamManipulators)
{
    std::ostringstream os;
    os << AnsiTerm::reset;
    ASSERT_EQ("\x1B[0m", os.str());

    os << AnsiTerm::underline
            << "Hello underline"
            << AnsiTerm::fontbright << " + bright"
            << AnsiTerm::reverse << " + reverse"
            << AnsiTerm::reset << " normal";
    ASSERT_EQ("\x1B[0m\x1B[4mHello underline\x1B[1m + bright\x1B[7m + reverse\x1B[0m normal", os.str());
//    std::cout << os.str() << std::endl;
//    
//    std::cout << AnsiTerm::blink
//            << "Hello blink"
//            << AnsiTerm::fgGreen << " + greenFg"
//            << AnsiTerm::bgRed << " + redBg"
//            << AnsiTerm::fgReset << " + resetFg"
//            << AnsiTerm::bgReset << " + resetBg"
//            << AnsiTerm::reset << " resetAttr"
//            << std::endl;
//    std::cout << AnsiTerm::fontbright << "Hello bright"
//            << AnsiTerm::fontnormal << " hello nobright"
//            << AnsiTerm::fontdim << " hello dim"
//            << AnsiTerm::fontnormal << " hello nodim"
//            << AnsiTerm::underline << " hello underline"
//            << AnsiTerm::nounderline << " hello nounderline"
//            << std::endl;
}
