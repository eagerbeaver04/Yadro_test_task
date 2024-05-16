#pragma once
#include "Time.h"

struct Event
{
    Time time;
    int id;
    std::string name;
    std::string extra_info;

    std::string serialize()
    {
        return Message::make_string(time.to_string(), " ",
                                    id, " ", name, " ", extra_info);
    }
};