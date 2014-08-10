#include "soil/MultiLogWriter.h"

namespace soil
{

MultiLogWriter& MultiLogWriter::add(LogWriter& writer)
{
    mItems.push_back(&writer);
    return *this;
}

MultiLogWriter& MultiLogWriter::remove(LogWriter& writer)
{
    return *this;
}

void MultiLogWriter::write(const LogFormat::Map& formatMap)
{
    // TODO: use auto in C++11
    for (std::vector<LogWriter*>::iterator it = mItems.begin(); it != mItems.end(); ++it)
    {
        (*it)->write(formatMap);
    }
}

void MultiLogWriter::write(const std::string& message)
{
}

} // namespace soil
