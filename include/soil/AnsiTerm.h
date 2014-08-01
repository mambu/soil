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
    enum Attribute
    {
        RESET     = 0,
        BRIGHT    = 1,
        DIM       = 2,
        UNDERLINE = 3,
        BLINK     = 4,
        REVERSE   = 7,
        HIDDEN    = 8,
        NO_ATTR   = 99
    };

    enum Colour
    {
        BLACK   = 0,
        RED     = 1,
        GREEN   = 2,
        YELLOW  = 3,
        BLUE    = 4,
        MAGENTA = 5,
        CYAN    = 6,
        WHITE   = 7,
        NO_COLOUR= 99              
    };

    static std::string format(Attribute attribute, Colour foreground, Colour background);
    static std::string reset();

    static std::string attr(Attribute attribute);
    static std::string fg(Colour c);
    static std::string bg(Colour c);

    // ostream formatters
    // attributes
    static std::ostream& reset (std::ostream& os);
    static std::ostream& bright (std::ostream& os);
    static std::ostream& dim (std::ostream& os);
    static std::ostream& underline (std::ostream& os);
    static std::ostream& blink (std::ostream& os);
    static std::ostream& reverse (std::ostream& os);
    static std::ostream& hidden (std::ostream& os);
    // foreground colours
    static std::ostream& fgBlack (std::ostream& os);
    static std::ostream& fgRed (std::ostream& os);
    static std::ostream& fgGreen (std::ostream& os);
    static std::ostream& fgYellow (std::ostream& os);
    static std::ostream& fgBlue (std::ostream& os);
    static std::ostream& fgMagenta (std::ostream& os);
    static std::ostream& fgCyan (std::ostream& os);
    static std::ostream& fgWhite (std::ostream& os);
    // background colours
    static std::ostream& bgBlack (std::ostream& os);
    static std::ostream& bgRed (std::ostream& os);
    static std::ostream& bgGreen (std::ostream& os);
    static std::ostream& bgYellow (std::ostream& os);
    static std::ostream& bgBlue (std::ostream& os);
    static std::ostream& bgMagenta (std::ostream& os);
    static std::ostream& bgCyan (std::ostream& os);
    static std::ostream& bgWhite (std::ostream& os);

private:
    static std::string command();
    static std::string attrString(Attribute attr);
    static std::string fgString(Colour c);
    static std::string bgString(Colour c);
};

} // namespace soil

#endif //SOIL_ANSITERM_H

