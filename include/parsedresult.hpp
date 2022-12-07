#ifndef PARSEDRESULT_HPP
#define PARSEDRESULT_HPP

#include <iostream>
#include <vector>

struct ParsedResult {
public:
    std::string url_;
    std::string format_;

public:
    bool operator==(const ParsedResult &_parsed) const noexcept {
        return url_ == _parsed.url_;
    }
    bool operator<(const ParsedResult &_parsed) const noexcept {
        return url_ < _parsed.url_;
    }
};

using ParsedVector = std::vector<ParsedResult>;

#endif 