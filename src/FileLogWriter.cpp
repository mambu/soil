#include "soil/FileLogWriter.h"

namespace soil
{

FileLogWriter::FileLogWriter(const std::string& filename, bool append)
    : mFile(filename.c_str(), append
                              ? std::ios_base::out | std::ios_base::app
                              : std::ios_base::out)
{
    if (!mFile.is_open())
    {
        // TODO: handle error
    }
}

} // namespace soil
