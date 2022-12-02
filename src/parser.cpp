#include "parser.hpp"

bool Parser::parse(const std::string &_answer, 
                   const std::string &_formats) noexcept {
    std::sregex_iterator begin { _answer.cbegin(), _answer.cend(), regular_ };
    std::sregex_iterator end { };

    for (auto i { begin }; i != end; ++i) {
        parsed_.emplace_back(i->str());
    }

    if (!parsed_.size()) {
        return false;
    }

    deleteCopy();

    return true;
}
