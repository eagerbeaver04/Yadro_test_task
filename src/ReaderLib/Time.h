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
    
    bool operator<(const Time &time) const 
    {
        int time_minutes = 60 * value.first + value.second;
        int lower_bound_minutes = 60 * time.value.first + time.value.second;
        if (time_minutes < lower_bound_minutes)
            return true;
        return false;
    }

    bool operator > (const Time& time) const
    {
        int time_minutes = 60 * value.first + value.second;
        int upper_bound_minutes = 60 * time.value.first + time.value.second;
        if (time_minutes > upper_bound_minutes)
            return true;
        return false;
    }
    
    bool operator ==(const Time& time) const
    {
        return value.first == time.value.first && value.second == time.value.second;
    }

    bool operator!=(const Time &time) const
    {
        return !(*this == time);
    }

    bool operator >= (const Time& time) const
    {
        return *this > time || *this == time;
    }
    
    bool operator<=(const Time &time) const
    {
        return *this < time || *this == time;
    }

    Time &operator+=(const Time &time)
    {
        value.second += time.value.second;
        if (value.second >= 60)
        {
            value.second -= 60;
            value.first += 1;
        }
        value.first += time.value.first;
        return *this;
    }

    Time &operator-=(const Time &time)
    {
        if (value.second < time.value.second)
        {
            value.second += 60;
            value.first -= 1;
        }
        value.second -= time.value.second;
        value.first -= time.value.first;
        return *this;
    }

    Time operator-(const Time &time) const
    {
        if(*this >= time)
        {
            Time result = *this;
            result -= time;
            return result;
        }
        Time result = time;
        result -=*this;
        return result;
    }

    Time operator+(const Time &time) const
    {
        Time sum = *this;
        sum += time;
        return sum;
    }

    int ceil_to_hours() const
    {
        return value.second == 0 ? value.first : value.first+1;
    }
};
