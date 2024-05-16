#include "Reader.h"

void Reader::read(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file " <<  filename << std::endl;
        return;
    }


    std::string line;

    std::getline(file, line);
    int number_of_tables = std::atoi(line.c_str());
    std::getline(file, line);
    std::pair<Time, Time> opening_time = Parser::parse_time_line(line);

    std::getline(file, line);
    int cost_per_hour = std::atoi(line.c_str());

    Computer_club club(number_of_tables, cost_per_hour, opening_time) ;

    std::cout << opening_time.first.to_string() << std::endl;

    Event event;

    while (std::getline(file, line))
    {   
        try
        {
            event = Parser::parse_action_line(line);
            std::cout << event.serialize() << std::endl;
        }
        catch(const std::exception& error)
        {
            std::cerr << error.what() << std::endl;
            continue;
        }
        switch (event.id)
        {
        case 1:
            if (event.time < opening_time.first || event.time > opening_time.second)
            {
                std::cerr << Message::make_string(event.time.to_string(), " ", 13, " ", "NotOpenYet")
                          << std::endl;
                continue;
            }
            try_catch_call(&Computer_club::add_client, &club, event);          
            break;
        case 2:
            try_catch_call(&Computer_club::sit_down, &club, event);
            break;
        default://other cases
         break;
        }
    }

    std::cout << opening_time.second.to_string() << std::endl;

    file.close();

}