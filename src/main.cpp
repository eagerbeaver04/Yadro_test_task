#include "ReaderLib/Reader.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Incorrect input" << std::endl;
        return 0;
    }
    
    Reader::read(argv[1]);

    return 0;
}