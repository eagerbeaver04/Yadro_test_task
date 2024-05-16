#include "Reader.h"

Computer_club Reader::read(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error(Message::make_string("Error: Unable to open file ", filename));
    

    using time = std::pair<int, int>;

    std::string line;

    std::getline(file, line);
    int number_of_tables = std::atoi(line.c_str());
    std::getline(file, line);
    std::pair<time, time> opening_time = Parser::parse_time_line(line);
    std::getline(file, line);
    int cost_per_hour = std::atoi(line.c_str());

    Computer_club club(number_of_tables, cost_per_hour, opening_time) ;
    std::cout << number_of_tables << " "<< cost_per_hour << " ";
    std::cout << opening_time.first.first << " " << opening_time.first.second << " "
              << opening_time.second.first << " " << opening_time.second.second;
    while (std::getline(file, line))
    {
        //do stuff
    }

    file.close();

    return club;
}