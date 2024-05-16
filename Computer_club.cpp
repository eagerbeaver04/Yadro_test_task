#include "Computer_club.h"

void Computer_club::count_client_activity(int table_index, Time event_time)
{
    Time current = tables[table_index].start_time - event_time;
    employment[table_index] += current;
    profit[table_index]+=current.ceil_to_hours() * cost_per_hour;
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
            count_client_activity(index, event.time);
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