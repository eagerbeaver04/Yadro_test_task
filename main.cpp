#include "Reader.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Incorrect input" << std::endl;
        return 1;
    }
    
    Reader::read(argv[1]);


}