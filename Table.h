#pragma once

#include "Event.h"
#include <queue>
#include <iostream>

struct Table
{
    bool is_avaliable;
    std::string name;
    Time start_time;
    Table() : is_avaliable(true), name(), start_time() {}
    Table(bool flag, const std::string name1, Time time1) : 
        is_avaliable(flag), name(name1), start_time(time1) {}
    Table& operator = (const Table& table)
    {
        if(this != &table)
        {
            is_avaliable = table.is_avaliable;
            name = table.name;
            start_time = table.start_time;
        }
        return *this;
    }
};