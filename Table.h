#pragma once

#include "Event.h"

struct Table
{
    bool is_available;
    std::string name;
    Time start_time;
    Table() : is_available(true), name(), start_time() {}
    Table(bool flag, const std::string name1, Time time1) : 
        is_available(flag), name(name1), start_time(time1) {}
    Table& operator = (const Table& table)
    {
        if(this != &table)
        {
            is_available = table.is_available;
            name = table.name;
            start_time = table.start_time;
        }
        return *this;
    }
};