#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <regex>

struct ParsedResult {
public:
    std::string url_;
    std::string format_;

public:
    bool operator==(const ParsedResult &_parsed) const noexcept {
        return url_ == _parsed.url_;
    }
};

class Parser {
private:
    using ParsedVector = std::vector<ParsedResult>;

private:
    std::regex   regular_;
    ParsedVector parsed_;

private:
    void deleteCopy() noexcept {
        parsed_.erase(std::unique(parsed_.begin(), parsed_.end()), parsed_.end());
    }

public:
    explicit Parser(const std::regex &_regular) noexcept :
        regular_ { _regular } { }

    auto &getParsed() const noexcept {
        return parsed_;
    }
    bool  parse(const std::string &_answer,
                const std::string &_formats) noexcept;
};

#endif 