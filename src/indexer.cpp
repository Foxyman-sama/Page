#include "indexer.hpp"

Indexer::Indexer(const std::string &_name, 
                 size_t             _size) noexcept { 
    fout_.open(_name, std::ios_base::binary);
    fout_ << "Размер: " << _size << '\n';                 
}

bool Indexer::write(const std::string &_data) noexcept {
    fout_ << _data << '\n';

    if ((fout_.bad()) || (fout_.fail())) {
        return false;
    }

    return true;
}
