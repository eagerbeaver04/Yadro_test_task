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
    bool operator < (const Time& time);
    bool operator > (const Time& time);
};
