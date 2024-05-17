#include "Parser.h"

Parser::str_iter Parser::first_space_after_word(Parser::str_iter& iter, Parser::str_iter& end_iter)
{
        return std::find_if(
            std::find_if_not(iter, end_iter, [](int c) { return std::isspace(c); })
                            , end_iter, [](int c) { return std::isspace(c); });
}

std::string Parser::trim(const std::string& line)
{
    auto front = std::find_if_not(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    auto back = std::find_if_not(line.rbegin(), line.rend(), [](int c)
                                 { return std::isspace(c); })
                    .base();
    return (back <= front ? std::string() : std::string(front, back));
}

void Parser::trim_in_place(std::string &line)
{
    auto front = std::find_if_not(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    auto back = std::find_if_not(line.rbegin(), line.rend(), [](int c)
                                 { return std::isspace(c); })
                    .base();
    line = (back <= front ? std::string() : std::string(front, back));
}

Time Parser::parse_time(const std::string& line)
{

    auto colon = std::find_if(line.begin(), line.end(), [](int c)
                             { return c == ':'; });
    if(colon == line.end())
        throw std::runtime_error(Message::make_string("Incorrect data in line: ", line));

    return {std::make_pair<int,int>(std::atoi(std::string(line.begin(), colon).c_str()),
     std::atoi(std::string(++colon, line.end()).c_str()))};
}

std::pair<Time, Time> 
    Parser::parse_time_line(const std::string& line)
{
    std::string trimmed_line = trim(line);
    std::vector<std::pair<int,int>> vector_of_time;
    auto middle_space = std::find_if(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    return {parse_time(std::string(line.begin(), middle_space)),
     parse_time(std::string(middle_space, line.end()))};
}

Event Parser::parse_action_line(const std::string& line)
{
    auto begin = line.begin();
    auto end = line.end();

    auto iter1 = first_space_after_word(begin,end);
    if(iter1 == end)
        throw std::runtime_error(Message::make_string("Incorrect data in line: ", line));

    Time opening_time = parse_time(std::string(begin, end));
    
    auto iter2 = first_space_after_word(iter1,end);

    if (iter2 == end)
        throw std::runtime_error(Message::make_string("Incorrect data in line: ", line));

    int id = std::atoi(std::string(iter1, iter2).c_str());

    iter1 = iter2;

    iter2 = first_space_after_word(iter2, end);
    
    std::string name = trim(std::string(iter1, iter2));

    iter1 = iter2;
    std::string extra_info = "";
    iter2 = first_space_after_word(iter2, end);
    if (iter2 != iter1) 
        extra_info = trim(std::string(iter1, iter2));

    return {opening_time, id, name, extra_info};
        
}