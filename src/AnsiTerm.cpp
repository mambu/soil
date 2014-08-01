#include "soil/AnsiTerm.h"
#include <sstream>

namespace soil
{

std::string AnsiTerm::format(AnsiTerm::Attribute attribute,
                             AnsiTerm::Colour foreground,
                             AnsiTerm::Colour background)
{
    if (attribute == NO_ATTR && foreground == NO_COLOUR && background == NO_COLOUR)
        return reset();

    std::string cmd = command();
    bool addSep = false;
    if (attribute != NO_ATTR)
    {
        cmd += attrString(attribute);
        addSep = true;
    }
    if (foreground != NO_COLOUR)
    {
        if (addSep)
        {
            cmd += ";";
        }
        cmd += fgString(foreground);
        addSep = true;
    }
    if (background != NO_COLOUR)
    {
        if (addSep)
        {
            cmd += ";";
        }
        cmd += bgString(background);
    }

    return cmd + "m";
}

std::string AnsiTerm::reset()
{
    return command() + "0m"; 
}

std::string AnsiTerm::attr(AnsiTerm::Attribute attribute)
{
    return command() + attrString(attribute) + "m";
}

std::string AnsiTerm::fg(AnsiTerm::Colour c)
{
    return command() + fgString(c) + "m";
}

std::string AnsiTerm::bg(AnsiTerm::Colour c)
{
    return command() + bgString(c) + "m";
}

std::ostream& AnsiTerm::reset (std::ostream& os)
{
    os << reset();
    return os;
}
std::ostream& AnsiTerm::bright (std::ostream& os)
{
    os << attr(BRIGHT);
    return os;
}
std::ostream& AnsiTerm::dim (std::ostream& os)
{
    os << attr(DIM);
    return os;
}
std::ostream& AnsiTerm::underline (std::ostream& os)
{
    os << attr(UNDERLINE);
    return os;
}
std::ostream& AnsiTerm::blink (std::ostream& os)
{
    os << attr(BLINK);
    return os;
}
std::ostream& AnsiTerm::reverse (std::ostream& os)
{
    os << attr(REVERSE);
    return os;
}
std::ostream& AnsiTerm::hidden (std::ostream& os)
{
    os << attr(HIDDEN);
    return os;
}

std::ostream& AnsiTerm::fgBlack (std::ostream& os)
{
    os << fg(BLACK);
    return os;
}
std::ostream& AnsiTerm::fgRed (std::ostream& os)
{
    os << fg(RED);
    return os;
}
std::ostream& AnsiTerm::fgGreen (std::ostream& os)
{
    os << fg(GREEN);
    return os;
}
std::ostream& AnsiTerm::fgYellow (std::ostream& os)
{
   os << fg(YELLOW);
   return os;
}
std::ostream& AnsiTerm::fgBlue (std::ostream& os)
{
    os << fg(BLUE);
    return os;
}
std::ostream& AnsiTerm::fgMagenta (std::ostream& os)
{
    os << fg(MAGENTA);
    return os;
}
std::ostream& AnsiTerm::fgCyan (std::ostream& os)
{
    os << fg(CYAN);
    return os;
}
std::ostream& AnsiTerm::fgWhite (std::ostream& os)
{
    os << fg(WHITE);
    return os;
}

std::ostream& AnsiTerm::bgBlack (std::ostream& os)
{
    os << bg(BLACK);
    return os;
}
std::ostream& AnsiTerm::bgRed (std::ostream& os)
{
    os << bg(RED);
    return os;
}
std::ostream& AnsiTerm::bgGreen (std::ostream& os)
{
    os << bg(GREEN);
    return os;
}
std::ostream& AnsiTerm::bgYellow (std::ostream& os)
{
    os << bg(YELLOW);
    return os;
}
std::ostream& AnsiTerm::bgBlue (std::ostream& os)
{
    os << bg(BLUE);
    return os;
}
std::ostream& AnsiTerm::bgMagenta (std::ostream& os)
{
    os << bg(MAGENTA);
    return os;
}
std::ostream& AnsiTerm::bgCyan (std::ostream& os)
{
    os << bg(CYAN);
    return os;
}
std::ostream& AnsiTerm::bgWhite (std::ostream& os)
{
    os << bg(WHITE);
    return os;
}

std::string AnsiTerm::command()
{
    static std::string cmd = "\x1B[";
    return cmd;
}

std::string AnsiTerm::attrString(Attribute attr)
{
    switch(attr)
    {
    case RESET:     return "0";
    case BRIGHT:    return "1";
    case DIM:       return "2";
    case UNDERLINE: return "3";
    case BLINK:     return "4";
    case REVERSE:   return "7";
    case HIDDEN:    return "8";
    default: return "";
    }
}

std::string AnsiTerm::fgString(Colour c)
{
    switch(c)
    {
    case AnsiTerm::BLACK:   return "30";
    case AnsiTerm::RED:     return "31";
    case AnsiTerm::GREEN:   return "32";
    case AnsiTerm::YELLOW:  return "33";
    case AnsiTerm::BLUE:    return "34";
    case AnsiTerm::MAGENTA: return "35";
    case AnsiTerm::CYAN:    return "36";
    case AnsiTerm::WHITE:   return "37";
    default: return "";
    }
}

std::string AnsiTerm::bgString(Colour c)
{
    switch(c)
    {
    case AnsiTerm::BLACK:   return "40";
    case AnsiTerm::RED:     return "41";
    case AnsiTerm::GREEN:   return "42";
    case AnsiTerm::YELLOW:  return "43";
    case AnsiTerm::BLUE:    return "44";
    case AnsiTerm::MAGENTA: return "45";
    case AnsiTerm::CYAN:    return "46";
    case AnsiTerm::WHITE:   return "47";
    default: return "";
    }
}

} // namespace soil
