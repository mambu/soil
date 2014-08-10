#include "soil/LogWriter.h"

namespace soil
{

void LogWriter::setFormat(const LogFormat& logFormat)
{
    mFormat = logFormat;
}

void LogWriter::write(const LogFormat::Map& formatMap)
{
    write(mFormat.get(formatMap));
}

} // namespace soil
