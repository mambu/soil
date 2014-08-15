/* 
 * File: AnsiTerm.h
 *
 * Copyright (c) 2014 Marco Ambu
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef SOIL_ANSITERM_H
#define SOIL_ANSITERM_H

#include <string>
#include <ostream>

namespace soil
{

class AnsiTerm
{
public:
    enum class Style
    {
        FONT_BRIGHT,
        FONT_DIM,
        FONT_NORMAL,
        UNDERLINE,
        NO_UNDERLINE,
        BLINK,
        NO_BLINK,
        REVERSE,
        NO_REVERSE,
        HIDDEN,
        NO_HIDDEN,
        CROSSED,
        NO_CROSSED,
        NONE
    };

    enum class Colour : char
    {
        BLACK   = '0',
        RED     = '1',
        GREEN   = '2',
        YELLOW  = '3',
        BLUE    = '4',
        MAGENTA = '5',
        CYAN    = '6',
        WHITE   = '7',
        NONE    = '9'              
    };

    static std::string format(Style style, Colour foreground, Colour background);
    static std::string reset();

    static std::string style(Style style);
    static std::string fg(Colour c);
    static std::string bg(Colour c);

    // ostream formatters
    // attributes
    static std::ostream& reset (std::ostream& os);

    static std::ostream& fontbright (std::ostream& os);
    static std::ostream& fontdim (std::ostream& os);
    static std::ostream& fontnormal (std::ostream& os);
    static std::ostream& underline (std::ostream& os);
    static std::ostream& nounderline (std::ostream& os);
    static std::ostream& blink (std::ostream& os);
    static std::ostream& noblink (std::ostream& os);
    static std::ostream& reverse (std::ostream& os);
    static std::ostream& noreverse (std::ostream& os);
    static std::ostream& hidden (std::ostream& os);
    static std::ostream& nohidden (std::ostream& os);
    static std::ostream& crossed (std::ostream& os);
    static std::ostream& nocrossed (std::ostream& os);
    // foreground colours
    static std::ostream& fgBlack (std::ostream& os);
    static std::ostream& fgRed (std::ostream& os);
    static std::ostream& fgGreen (std::ostream& os);
    static std::ostream& fgYellow (std::ostream& os);
    static std::ostream& fgBlue (std::ostream& os);
    static std::ostream& fgMagenta (std::ostream& os);
    static std::ostream& fgCyan (std::ostream& os);
    static std::ostream& fgWhite (std::ostream& os);
    static std::ostream& fgReset (std::ostream& os);
    // background colours
    static std::ostream& bgBlack (std::ostream& os);
    static std::ostream& bgRed (std::ostream& os);
    static std::ostream& bgGreen (std::ostream& os);
    static std::ostream& bgYellow (std::ostream& os);
    static std::ostream& bgBlue (std::ostream& os);
    static std::ostream& bgMagenta (std::ostream& os);
    static std::ostream& bgCyan (std::ostream& os);
    static std::ostream& bgWhite (std::ostream& os);
    static std::ostream& bgReset (std::ostream& os);

private:
    static const std::string csi;
    static std::string styleString(Style attr);
    static std::string fgString(Colour c);
    static std::string bgString(Colour c);
};

} // namespace soil

#endif //SOIL_ANSITERM_H

