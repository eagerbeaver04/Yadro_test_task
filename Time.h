#pragma once
#include "Message.h"

struct Time
{
    std::pair<int,int> value;
    std::string to_string() const
    {
        std::ostringstream os;
        if (value.first < 10)
            os << 0;
        os << value.first << ":";
        if (value.second < 10)
            os << 0;
        os << value.second;
        return os.str();
    }
    Time operator - (const Time& time);
    Time operator + (const Time& time);
    bool operator<(const Time &time)
    {
        int time_minutes = 60 * value.first + value.second;
        int lower_bound_minutes = 60 * time.value.first + time.value.second;
        if (time_minutes < lower_bound_minutes)
            return true;
        return false;
    }
    bool operator > (const Time& time)
    {
        int time_minutes = 60 * value.first + value.second;
        int upper_bound_minutes = 60 * time.value.first + time.value.second;
        if (time_minutes > upper_bound_minutes)
            return true;
        return false;
    }
};
