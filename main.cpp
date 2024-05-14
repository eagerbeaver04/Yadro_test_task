#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Incorrect input" << std::endl;
        return 1;
    }
    const std::string filename = argv[1];


}