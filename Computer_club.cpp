#include "Computer_club.h"

void Computer_club::add_client(const std::string& client_name)
{
    if(clients_queue.find(client_name) == clients_queue.end())
        clients_queue.insert(client_name);
    else
        throw(std::runtime_error("YouShallNotPass"));
}