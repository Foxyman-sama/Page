#include "cachewriter.hpp"

bool CacheWriter::write(const ParsedVector &_parsed) noexcept {
    size_t size { _parsed.size() };

    for (size_t i { }; i < size; ++i) {
        if (i == size - 1) {
            fout_ << _parsed[i].url_;
        }
        else {
            fout_ << _parsed[i].url_ << '\n';
        }

        if ((fout_.fail()) || (fout_.bad())) {
            return false;
        }
    }

    return true;
}
