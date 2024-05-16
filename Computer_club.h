#pragma once

#include "Table.h"
#include <vector>

class Computer_club
{
private:
    using time = std::pair<int,int>;
    int number_of_tables;
    int cost_per_hour;
    std::pair<time, time> opening_time;
    std::vector<Table> tables;
    std::vector<int> profit;
public:
    Computer_club(int number_of_tables1, int cost_per_hour1, std::pair<time, time> opening_time1) : 
    number_of_tables(number_of_tables1), cost_per_hour(cost_per_hour1), opening_time(opening_time1)
    {
        profit = std::vector(number_of_tables,0);
        tables = std::vector(number_of_tables, Table());
    }
};