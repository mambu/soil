#include "soil/AnsiTerm.h"
#include <sstream>

namespace soil
{
    
const std::string AnsiTerm::csi = "\x1B[";

std::string AnsiTerm::format(Style style,
                             Colour foreground,
                             Colour background)
{
    if (style == Style::NONE
        && foreground == Colour::NONE
        && background == Colour::NONE)
    {
        return reset();
    }

    std::ostringstream cmd;
    cmd << csi;
    bool addSep = false;
    if (style != Style::NONE)
    {
        cmd << styleString(style);
        addSep = true;
    }
    if (foreground != Colour::NONE)
    {
        if (addSep)
        {
            cmd << ';';
        }
        cmd << fgString(foreground);
        addSep = true;
    }
    if (background != Colour::NONE)
    {
        if (addSep)
        {
            cmd << ';';
        }
        cmd << bgString(background);
    }

    cmd << 'm';
    return cmd.str();
}

std::string AnsiTerm::reset()
{
    return csi + "0m"; 
}

std::string AnsiTerm::style(AnsiTerm::Style style)
{
    return csi + styleString(style) + "m";
}

std::string AnsiTerm::fg(AnsiTerm::Colour c)
{
    return c == Colour::NONE ? "" : csi + fgString(c) + "m";
}

std::string AnsiTerm::bg(AnsiTerm::Colour c)
{
    return c == Colour::NONE ? "" : csi + bgString(c) + "m";
}

std::ostream& AnsiTerm::reset(std::ostream& os)
{
    os << reset();
    return os;
}
std::ostream& AnsiTerm::fontbright(std::ostream& os)
{
    os << style(Style::FONT_BRIGHT);
    return os;
}
std::ostream& AnsiTerm::fontdim(std::ostream& os)
{
    os << style(Style::FONT_DIM);
    return os;
}
std::ostream& AnsiTerm::fontnormal(std::ostream& os)
{
    os << style(Style::FONT_NORMAL);
    return os;
}
std::ostream& AnsiTerm::underline(std::ostream& os)
{
    os << style(Style::UNDERLINE);
    return os;
}
std::ostream& AnsiTerm::nounderline(std::ostream& os)
{
    os << style(Style::NO_UNDERLINE);
    return os;
}
std::ostream& AnsiTerm::blink(std::ostream& os)
{
    os << style(Style::BLINK);
    return os;
}
std::ostream& AnsiTerm::noblink(std::ostream& os)
{
    os << style(Style::NO_BLINK);
    return os;
}
std::ostream& AnsiTerm::reverse(std::ostream& os)
{
    os << style(Style::REVERSE);
    return os;
}
std::ostream& AnsiTerm::noreverse(std::ostream& os)
{
    os << style(Style::NO_REVERSE);
    return os;
}
std::ostream& AnsiTerm::hidden(std::ostream& os)
{
    os << style(Style::HIDDEN);
    return os;
}
std::ostream& AnsiTerm::nohidden(std::ostream& os)
{
    os << style(Style::HIDDEN);
    return os;
}

std::ostream& AnsiTerm::fgBlack(std::ostream& os)
{
    os << fg(Colour::BLACK);
    return os;
}
std::ostream& AnsiTerm::fgRed(std::ostream& os)
{
    os << fg(Colour::RED);
    return os;
}
std::ostream& AnsiTerm::fgGreen(std::ostream& os)
{
    os << fg(Colour::GREEN);
    return os;
}
std::ostream& AnsiTerm::fgYellow(std::ostream& os)
{
   os << fg(Colour::YELLOW);
   return os;
}
std::ostream& AnsiTerm::fgBlue(std::ostream& os)
{
    os << fg(Colour::BLUE);
    return os;
}
std::ostream& AnsiTerm::fgMagenta(std::ostream& os)
{
    os << fg(Colour::MAGENTA);
    return os;
}
std::ostream& AnsiTerm::fgCyan(std::ostream& os)
{
    os << fg(Colour::CYAN);
    return os;
}
std::ostream& AnsiTerm::fgWhite(std::ostream& os)
{
    os << fg(Colour::WHITE);
    return os;
}
std::ostream& AnsiTerm::fgReset(std::ostream& os)
{
    os << fg(Colour::NONE);
    return os;
}

std::ostream& AnsiTerm::bgBlack(std::ostream& os)
{
    os << bg(Colour::BLACK);
    return os;
}
std::ostream& AnsiTerm::bgRed(std::ostream& os)
{
    os << bg(Colour::RED);
    return os;
}
std::ostream& AnsiTerm::bgGreen(std::ostream& os)
{
    os << bg(Colour::GREEN);
    return os;
}
std::ostream& AnsiTerm::bgYellow(std::ostream& os)
{
    os << bg(Colour::YELLOW);
    return os;
}
std::ostream& AnsiTerm::bgBlue(std::ostream& os)
{
    os << bg(Colour::BLUE);
    return os;
}
std::ostream& AnsiTerm::bgMagenta(std::ostream& os)
{
    os << bg(Colour::MAGENTA);
    return os;
}
std::ostream& AnsiTerm::bgCyan(std::ostream& os)
{
    os << bg(Colour::CYAN);
    return os;
}
std::ostream& AnsiTerm::bgWhite(std::ostream& os)
{
    os << bg(Colour::WHITE);
    return os;
}
std::ostream& AnsiTerm::bgReset(std::ostream& os)
{
    os << bg(Colour::NONE);
    return os;
}


std::string AnsiTerm::styleString(AnsiTerm::Style attr)
{
    switch(attr)
    {
    case Style::FONT_BRIGHT:    return "1";
    case Style::FONT_DIM:       return "2";
    case Style::FONT_NORMAL:    return "22";
    case Style::UNDERLINE:      return "4";
    case Style::NO_UNDERLINE:   return "24";
    case Style::BLINK:          return "5";
    case Style::NO_BLINK:       return "25";
    case Style::REVERSE:        return "7";
    case Style::NO_REVERSE:     return "27";
    case Style::HIDDEN:         return "8";
    case Style::NO_HIDDEN:      return "28";
    case Style::CROSSED:        return "9";
    case Style::NO_CROSSED:     return "29";
    default: return "";
    }
}

std::string AnsiTerm::fgString(AnsiTerm::Colour c)
{
    std::string s(1, '3');
    s += static_cast<char>(c);
    return s;
}

std::string AnsiTerm::bgString(AnsiTerm::Colour c)
{
    std::string s(1, '4');
    s += static_cast<char>(c);
    return s;
}


} // namespace soil
