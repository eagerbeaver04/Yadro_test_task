#pragma once
#include "Time.h"

struct Event
{
    Time time;
    int id;
    std::string name;
    std::string extra_info;

    bool is_time_less(const Time& lower_bound)
    {
        int time_minutes = 60 * time.value.first + time.value.second;
        int lower_bound_minutes = 60 * lower_bound.value.first + lower_bound.value.second;
        if(time_minutes < lower_bound_minutes)
            return true;
        return false;
    }
    bool is_time_bigger(const Time &upper_bound)
    {
        int time_minutes = 60 * time.value.first + time.value.second;
        int upper_bound_minutes = 60 * upper_bound.value.first + upper_bound.value.second;
        if (time_minutes > upper_bound_minutes)
            return true;
        return false;
    }
    std::string serialize()
    {
        return Message::make_string(time.to_string(), " ",
                                    id, " ", name, " ", extra_info);
    }
};