#include <fstream>
#include <string>
#include <iostream>

class Reader
{
private:
    const std::string filename;
public:
    explicit Reader(const std::string& str) noexcept: filename(str) {}
    
};