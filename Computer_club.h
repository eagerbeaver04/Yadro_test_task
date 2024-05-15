#include "Table.h"
#include <vector>
#include <sstream>

class Computer_club
{
private:
    int number_of_tables;
    std::vector<int> profit;
    int cost_per_hour;
    std::pair<int,int> opening_time;
    std::pair<int,int> closing_time;
    std::vector<Table> tables; 
};