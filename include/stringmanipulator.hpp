#ifndef STRINGMANIPULATOR_HPP
#define STRINGMANIPULATOR_HPP

#include <string>
#include <vector>

#define DEFAULT { ':', '\\', '/', '?', '&' }

class StringManipulator {
public:
    static void deleteSymbols(std::string             &_str,
                              const std::vector<char> &_symbols = DEFAULT) noexcept;
    static void replace(std::string       &_str, 
                        const std::string &_current,
                        const std::string &_new) noexcept;
};

#endif 