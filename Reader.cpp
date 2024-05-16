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
    Event event;
    while (std::getline(file, line))
    {
        event =  Parser::parse_action_line(line);
        std::cout << event.serialize() << std::endl;
        
        switch (event.id)
        {
        case 1:
            if (event.is_time_less(opening_time.first) || event.is_time_bigger(opening_time.second))
            {
                std::cout << "NotOpenYet" << std::endl;
                continue;
            }
         break;
       
        default:
         break;
        }
    }

    file.close();

    return club;
}