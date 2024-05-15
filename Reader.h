#pragma once

#include "Parser.h"
#include <fstream>

class Reader
{

public:
    static Computer_club read(const std::string& filename);
};