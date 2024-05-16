#pragma once

#include "Event.h"
#include <queue>
#include <iostream>

struct Client_info
{
    std::string name;
    std::pair<int, int> start_time;
};

class Table
{
private:
    std::queue<Client_info> clients_queue;
};