#include "Message.h"

struct Event
{
    using time_t = std::pair<int, int>;
    time_t time;
    int id;
    std::string name;
    std::string extra_info;
};