#pragma once

#include "Computer_club.h"
#include <algorithm>

class Parser
{
private:
    using time = std::pair<int,int>;
    using str_iter = std::string::const_iterator;
    static str_iter first_space_after_word(str_iter &iter, str_iter& end_iter);
public:
    static std::string trim(const std::string& line);
    static void trim_in_place(std::string& line);
    static time parse_time(const std::string &line);
    static std::pair<time,time> parse_time_line(const std::string& line);
    static Event parse_action_line(const std::string& line);
    static std::string time_to_string(const time& pair);
    static std::string Event_to_string(const Event& event);
    
};