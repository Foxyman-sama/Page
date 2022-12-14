#include "indexer.hpp"

Indexer::Indexer(const std::string &_name, 
                 size_t             _size) noexcept { 
    fout_.open(_name, std::ios_base::binary);
    fout_ << _size << '\n';                 
}

bool Indexer::write(const ParsedVector &_parsed) noexcept {
    size_t size { _parsed.size() };

    for (size_t i { }; i < size; ++i) {
        fout_.width(5);
        fout_ << i + 1 << ' ';

        if (i == size - 1) {
            fout_ << _parsed[i].url_;
        }
        else {
            fout_ << _parsed[i].url_ << '\n';
        }

        if ((fout_.bad()) || (fout_.fail())) {
            return false;
        }
    }

    return true;
}
