#include "Table.h"
#include <vector>

class Computer_club
{
private:
    int number_of_tables;
    int profit;
    std::pair<int,int> opening_time;
    std::pair<int,int> closing_time;
    std::vector<Table> tables; 
};