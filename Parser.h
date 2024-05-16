#pragma once

#include "Computer_club.h"
#include <algorithm>

class Parser
{
private:
    using time = std::pair<int,int>;
public:
    static std::string trim(const std::string& line);
    static void trim_in_place(std::string& line);
    static time parse_time(const std::string &line);
    static std::pair<time,time> parse_time_line(const std::string& line);
    static Event parse_action_line(const std::string& line);

};