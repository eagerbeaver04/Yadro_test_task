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
    Time& operator+=(const Time &time)
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
    Time& operator -=(const Time& time)
    {
        if (*this >= time)
        {
            value.second -= time.value.first;
            if (value.second < 0)
            {
                value.second += 60;
                value.first -= 1;
            }
            value.first -= time.value.first;
            return *this;
        }
        Time sub = time;
        sub.value.second -= value.first;
        if (sub.value.second < 0)
        {
            sub.value.second += 60;
            sub.value.first -= 1;
        }
        sub.value.first -= value.first;
        *this = sub;
        return *this;
    }
    Time operator - (const Time& time) const
    {   
        Time sub = *this;
        sub-=time;
        return sub;
    }
    Time operator + (const Time& time) const
    {
        Time sum = *this;
        sum+=time;
        return sum;
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

    bool operator >= (const Time& time) const
    {
        return *this > time || *this == time;
    }
    bool operator<=(const Time &time) const
    {
        return *this < time || *this == time;
    }

    int ceil_to_hours() const
    {
        return value.second == 0 ? value.first : value.first+1;
    }



};
