#include "checker.hpp"

bool Checker::read(ParsedVector &_parsed) noexcept {
    bool open { false };

    for (size_t i { }; i < _parsed.size(); ++i) {
        fin_.open(folder_ + "\\" + _parsed[i].format_);

        if (fin_.is_open()) {
            open = true;

            _parsed.erase(_parsed.begin() + i--);
        }

        fin_.close();
    }

    return open;
}
