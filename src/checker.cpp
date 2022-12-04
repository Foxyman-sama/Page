#include "checker.hpp"

void Checker::check(ParsedVector &_parsed) noexcept {
    for (size_t i { }; i < _parsed.size(); ++i) {
        checker_.open(folder_ + "/" + _parsed[i].format_);

        if (checker_.is_open()) {
            _parsed.erase(_parsed.begin() + i--);
        }

        checker_.close();
    }
}
