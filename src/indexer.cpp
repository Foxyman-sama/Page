#include "indexer.hpp"

void Indexer::indexing(const std::string &_text) noexcept {
    saver_ << ' ' << _text << '\n';
}
