#include <string>
#include <sstream>
#include <exception>

struct bad_from_string : std::invalid_argument {
    bad_from_string(std::string const & s) noexcept : std::invalid_argument(s) {}
};

template<class T>
T from_string(std::string const & s) {
    std::istringstream ss(s);
    T res;
    ss >> std::noskipws >> res;
    if (ss.fail())
        throw bad_from_string("cast failure: " + s);
    if (ss.peek() != EOF)
        throw bad_from_string("eof not reached: " + s);
    return res;
}