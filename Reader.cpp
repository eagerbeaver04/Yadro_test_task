#include "Reader.h"

Computer_club Reader::read(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::ostringstream error_stream;
        error_stream << "Error: Unable to open file " << filename << std::endl;
        throw std::runtime_error(error_stream.str());
    }

    using time = std::pair<int, int>;

    std::string line;

    std::getline(file, line);
    int number_of_tables = std::atoi(line.c_str());
    std::getline(file, line);
    std::pair<time, time> opening_time = Parser::parse_time_line(line);
    std::getline(file, line);
    int cost_per_hour = std::atoi(line.c_str());

    Computer_club club(number_of_tables, cost_per_hour, opening_time) ;
    
    while (std::getline(file, line))
    {
        //do stuff
    }

    file.close();
}