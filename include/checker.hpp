#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <fstream>
#include "parsedresult.hpp"

class Checker {
protected:
    std::ifstream checker_;
    std::string   folder_;

public:
    Checker(const std::string &_folder) noexcept :
        folder_ { _folder } { }

    void check(ParsedVector &_parsed) noexcept;
};

#endif 