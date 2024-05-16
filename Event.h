#include "Message.h"

struct Event
{
    using time1 = std::pair<int, int>;
    time1 time;
    int id;
    std::string name;
    std::string extra_info;
    std::string serialize()
    {
        return Message::make_string(time.first, ":", time.second, " ", id, " ", name, " ", extra_info);
    }
};