#include "Computer_club.h"

void Computer_club::count_client_activity(int table_index, Time event_time)
{
    Time current = event_time - tables[table_index].start_time;
    employment[table_index] += current;
    profit[table_index] += current.ceil_to_hours() * cost_per_hour;
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
        auto client = std::find_if(clients_queue.begin(), clients_queue.end(), 
         [&event](const std::string& str) {return str == event.name;});

        if(client != clients_queue.end())
        {
            if(tables[desired_table].is_available)
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
        {   return !table.is_available && table.name == event.name;});
    if(client != tables.end())
    {
        if (tables[desired_table].is_available)
        {
            int index = std::distance(tables.begin(), client);
            count_client_activity(index, event.time);
            (*client).is_available = true;
            tables[desired_table] = { false, event.name, event.time };
            return;
        }
        throw(std::runtime_error(Message::make_string(
            event.time.to_string(), " ", 13, " ", "PlaceIsBusy")));
    }
    throw(std::runtime_error(Message::make_string(
        event.time.to_string(), " ", 13, " ", "ClientUnknown")));
}


void Computer_club::client_wait(const Event& event)
{
    auto client = std::find(clients_queue.begin(), clients_queue.end(), event.name);
    if (client == clients_queue.end())
        throw(std::runtime_error(Message::make_string(
            event.time.to_string(), " ", 13, " ", "ClientUnknown")));

    int queue_size = std::distance(clients_queue.begin(), clients_queue.end());
    int number_of_available_tables = std::count_if(tables.begin(), tables.end(),
     [](const Table& table){return table.is_available == true;});

    if(queue_size > number_of_tables)
    {
        clients_queue.erase(client);
        std::cout << Message::make_string(
            event.time.to_string(), " ", 11, " ", event.name) << std::endl;
    }
    if (number_of_available_tables > 0)
    {
        throw(std::runtime_error(Message::make_string(
            event.time.to_string(), " ", 13, " ", "ICanWaitNoLonger!")));
    }
    
}

void Computer_club::erase_client(const Event &event)
{   
    
    {
        auto client = std::find_if(tables.begin(), tables.end(), [&event](Table &table)
                               { return !table.is_available && table.name == event.name; });
        if(client != tables.end())
        {
            int index = std::distance(tables.begin(), client);

            count_client_activity(index, event.time);
            (*client).is_available = true;    
            if(!clients_queue.empty())
            {
                std::string name = *clients_queue.begin();
                tables[index] = {false, name, event.time};
                clients_queue.erase(clients_queue.begin());
               std::cout << Message::make_string(
                    event.time.to_string(), " ", 12, " ", name, " ", index+1) << std::endl;
            }
            return;
        }
       
    }
    auto client = std::find(clients_queue.begin(), clients_queue.end(), event.name);
    if(client != clients_queue.end())
    {
        clients_queue.erase(client);
        return;
    }
    throw(std::runtime_error(Message::make_string(
        event.time.to_string(), " ", 13, " ", "ClientUnknown")));
}


void Computer_club::kick_out_clients()
{
    std::vector<std::string> clients;
    for(size_t i =0; i < tables.size(); ++i)
    {
        if(!tables[i].is_available)
        {
            tables[i].is_available = true;
            count_client_activity(i, opening_time.second);
            clients.push_back(tables[i].name);
        }
    }
    for(auto&& client : clients_queue)
       clients.push_back(client);
    
    std::sort(clients.begin(), clients.end());
    for(auto&& client : clients)
        std::cout << Message::make_string(
        opening_time.second.to_string(), " ", 11, " ", client) << std::endl;
}

void Computer_club::print_profit()
{
    for(size_t i =0; i< profit.size(); ++i)
        std::cout << Message::make_string(i+1, " ", profit[i], " ", employment[i].to_string())
         << std::endl;
}