#include "cachewriter.hpp"

bool CacheWriter::write(const std::string &_data) noexcept {
    fout_ << _data;

    if ((fout_.fail()) || (fout_.bad())) {
        return false;
    }

    return true;
}
