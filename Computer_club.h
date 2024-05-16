#pragma once

#include "Table.h"
#include <vector>
#include <set>
#include <algorithm>

class Computer_club
{
private:
    int number_of_tables;
    int cost_per_hour;
    std::pair<Time, Time> opening_time;
    std::set<std::string> clients_queue;
    std::vector<int> profit;
    std::vector<Table> tables;
    std::vector<Time> employment;
    void count_client_activity(int table_index, Time event_time);
public : 
    Computer_club(int number_of_tables1, int cost_per_hour1, std::pair<Time, Time> opening_time1) :
     number_of_tables(number_of_tables1), cost_per_hour(cost_per_hour1),
      opening_time(opening_time1), clients_queue()
    {
        profit = std::vector(number_of_tables,0);
        tables = std::vector(number_of_tables, Table());
        employment = std::vector(number_of_tables, Time());
    }

    void add_client(const Event& event);

    void sit_down(const Event& event);

    void client_wait(const Event& event);

    void erase_client(const Event& event);

};