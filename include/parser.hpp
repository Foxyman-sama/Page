#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <regex>
#include "parsedresult.hpp"
#include "vectormanipulator.hpp"

class Parser {
private:
    std::regex   regular_;
    ParsedVector parsed_;

public:
    explicit Parser(const std::regex &_regular) noexcept :
        regular_ { _regular } { }

    auto &getParsed() const noexcept {
        return parsed_;
    }
    bool  parse(const std::string &_answer) noexcept;
};

#endif 