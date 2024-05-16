#pragma once

#include "Message.h"

struct Event
{
    using time1 = std::pair<int, int>;
    time1 time;
    int id;
    std::string name;
    std::string extra_info;

    bool is_time_less(const time1& lower_bound)
    {
        int time_minutes = 60 * time.first + time.second;
        int lower_bound_minutes = 60 * lower_bound.first + lower_bound.second;
        if(time_minutes < lower_bound_minutes)
            return true;
        return false;
    }
    bool is_time_bigger(const time1 &upper_bound)
    {
        int time_minutes = 60 * time.first + time.second;
        int upper_bound_minutes = 60 * upper_bound.first + upper_bound.second;
        if (time_minutes > upper_bound_minutes)
            return true;
        return false;
    }
};