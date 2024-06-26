#pragma once

#include "Parser.h"
#include <fstream>
#include <functional>

class Reader
{
private:
    template <class F, class... Args>
    static auto try_catch_call(F &&fun, Args &&...args) noexcept
    {
        try
        {
            return std::invoke(std::forward<F>(fun), std::forward<Args>(args)...);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
public:
    static void read(const std::string& filename);
};