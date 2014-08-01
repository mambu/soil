#include "soil/FileLogWriter.h"

namespace soil
{

FileLogWriter::FileLogWriter(const std::string& filename, bool append)
    : mFile(filename.c_str())
{
    if (!mFile.is_open())
    {
        // TODO: handle error
    }
}
}
