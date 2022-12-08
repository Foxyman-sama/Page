#include "saver.hpp"

void Saver::save(const std::string &_text) noexcept { 
    saver_ << _text << '\n';
}
