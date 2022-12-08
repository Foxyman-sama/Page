#include "indexer.hpp"

void Indexer::save(const std::string &_text) noexcept {
    saver_ << ' ' << _text << '\n';
}
