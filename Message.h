#include <string>
#include <sstream>
#include <utility>

class Message
{
private:
    template<class T>
    static void make_string(std::ostringstream& os, T arg)
    {
        os << arg;
    }
    template<class T, class... Args>
    static void make_string(std::ostringstream& os, T arg, Args... args)
    {
        os << arg;
        make_string(os, std::forward<Args>(args)...);
    }
public:
    template<class... Args>
    static std::string make_string(Args... args)
    {
        std::ostringstream os;
        make_string(os, std::forward<Args>(args)...);
        return os.str();
    }
};