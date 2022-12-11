#include "saver.hpp"

bool Saver::write(const std::string &_data) noexcept {
    fout_ << _data << '\n';

    if ((fout_.bad()) || (fout_.fail())) {
        return false;
    }

    return true;
}
