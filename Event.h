#include <string>

static std::pair<int, int> 
    time_string_to_pair(const std::string& time)
{
    return { std::atoi(time.substr(0, 2).c_str()), std::atoi(time.substr(3, 2).c_str()) };
}

// class Event
// {
// private:
//     std::pair<int,int> time;
// }