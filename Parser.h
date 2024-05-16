#pragma once

#include "Computer_club.h"

class Parser
{
private:
    using str_iter = std::string::const_iterator;
    static str_iter first_space_after_word(str_iter &iter, str_iter& end_iter);
public:
    static std::string trim(const std::string& line);
    static void trim_in_place(std::string& line);
    static Time parse_time(const std::string &line);
    static std::pair<Time,Time> parse_time_line(const std::string& line);
    static Event parse_action_line(const std::string& line);


};