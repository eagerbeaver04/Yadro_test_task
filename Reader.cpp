#include "Reader.h"

Computer_club Reader::read()
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::ostringstream error_stream;
        error_stream << "Error: Unable to open file " << filename << std::endl;
        throw std::runtime_error(error_stream.str());
    }
    std::string line;
    while (getline(file, line))
       //do parse

    file.close();
}