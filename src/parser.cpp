#include "parser.hpp"

bool Parser::parse(const std::string &_answer) noexcept {
    std::sregex_iterator begin { _answer.cbegin(), _answer.cend(), regular_ };
    std::sregex_iterator end { };

    for (auto i { begin }; i != end; ++i) {
        std::string temp { i->str(2) };

        if (temp.find("https") == std::string::npos) {
            temp = "https:" + temp;
        }

        parsed_.emplace_back(temp);
    }

    if (!parsed_.size()) {
        return false;
    }

    VectorManipulator::deleteCopies(parsed_);

    return true;
}
