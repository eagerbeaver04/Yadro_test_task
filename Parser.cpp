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

void Parser::trim_in_place(std::string &line)
{
    auto front = std::find_if_not(line.begin(), line.end(), [](int c)
                                  { return std::isspace(c); });
    auto back = std::find_if_not(line.rbegin(), line.rend(), [](int c)
                                 { return std::isspace(c); })
                    .base();
    line = (back <= front ? std::string() : std::string(front, back));
}

std::pair<int,int> Parser::parse_time(const std::string& line)
{

    auto colon = std::find_if(line.begin(), line.end(), [](int c)
                             { return c == ':'; });
    if(colon == line.end())
    {
        throw std::runtime_error(Message::make_string("Incorrect data in line: ", line));
    }
    return {std::atoi(std::string(line.begin(), colon).c_str()),
     std::atoi(std::string(++colon, line.end()).c_str())};
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

// Event Parser::parse_action_line(const std::string& line)
// {
//     std::string copy_line = line;
//     trim_in_place(copy_line);

//     auto front = std::find_if(line.begin(), line.end(), [](int c)
//                                      { return std::isspace(c); });

//     time action_time = parse_time(std::string(line.begin(), front));


//     auto back = std::find_if_not(front, line.end(), [](int c)
//                                   { return std::isspace(c); });

//     if(back == copy_line.end())
//         throw std::runtime_error(Message::make_string("Incorrect data in line: ", std::ref(line)));

//     int id = std::atoi(std::string(front, ++back).c_str());


// }