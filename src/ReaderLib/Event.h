#pragma once

#include "Time.h"

struct Event
{
    Time time;
    int id;
    std::string name;
    std::string extra_info;

    std::string serialize() const
    {
        return Message::make_string(time.to_string(), " ",
                                    id, " ", name, " ", extra_info);
    }

    bool operator ==(const Event& event) const
    {
        return time == event.time && id == event.id &&
         name == event.name && extra_info == event.extra_info;
    }

    bool operator !=(const Event& event) const
    {
        return !(*this == event);
    }
};