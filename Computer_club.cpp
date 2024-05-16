#include "Computer_club.h"

int Computer_club::get_current_profit(int table_index, Time event_time)
{
    return 0; // do logic
}

void Computer_club::add_client(const Event& event)
{
    if(clients_queue.find(event.name) == clients_queue.end())
        clients_queue.insert(event.name);
    else
        throw(std::runtime_error(Message::make_string(
             event.time.to_string(), " ", 13, " ", "YouShallNotPass")));
}

void Computer_club::sit_down(const Event& event)
{
    int desired_table = std::atoi(event.extra_info.c_str());
    --desired_table;
    {
        auto client = std::find_if(clients_queue.begin(), clients_queue.end(), [&event](const std::string& str)
                                            {return str == event.name;});

        if(client != clients_queue.end())
        {
            if(tables[desired_table].is_avaliable)
            {
                tables[desired_table]=Table(false, event.name, event.time);
                clients_queue.erase(client);
                return;
            }
            throw(std::runtime_error(Message::make_string(
                event.time.to_string()," ", 13," ", "PlaceIsBusy")));
        }
    }
    auto client = std::find_if(tables.begin(), tables.end(), [&event](Table& table)
        {   return table.is_avaliable && table.name == event.name;});
    if(client != tables.end())
    {
        if (tables[desired_table].is_avaliable)
        {
            int index = std::distance(tables.begin(), client) - 1;
            profit[index] += get_current_profit(index, event.time);
            //employment[index]+=
            (*client).is_avaliable = true;
            tables[desired_table] = { false, event.name, event.time };
            return;
        }
        throw(std::runtime_error(Message::make_string(
            event.time.to_string(), " ", 13, " ", "PlaceIsBusy")));
    }
    throw(std::runtime_error(Message::make_string(
        event.time.to_string(), " ", 13, " ", "ClientUnknown")));
}