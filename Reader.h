#include "Computer_club.h"
#include <fstream>

class Reader
{
private:
    const std::string filename;
public:
    explicit Reader(const std::string& str) noexcept: filename(str) {}
    Computer_club read();

};