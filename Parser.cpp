#include "Parser.h"
std::string Parser::trim(const std::string& line)
{
    auto front = std::find_if_not(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    auto back = std::find_if_not(line.rbegin(), line.rend(), [](int c)
                                 { return std::isspace(c); })
                    .base();
    return (back <= front ? std::string() : std::string(front, back));
}

std::pair<int,int> Parser::parse_time(const std::string& line)
{
    std::string trimmed_line = trim(line);
    return {std::atoi(trimmed_line.substr(0, 2).c_str()),
     std::atoi(trimmed_line.substr(3, 2).c_str())};
}

std::pair<std::pair<int, int>,std::pair<int,int>> 
    Parser::parse_time_line(const std::string& line)
{
    std::string trimmed_line = trim(line);
    std::vector<std::pair<int,int>> vector_of_time;
    auto middle_space = std::find_if(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    return {parse_time(std::string(line.begin(), middle_space)),
     parse_time(std::string(middle_space, line.end()))};
}