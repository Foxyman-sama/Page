#include "cacher.hpp"

Cacher::Cacher(const std::string &_filename,
               OpenType           _type) noexcept  {
    std::string temp { _filename };

    StringManipulator::deleteSymbols(temp);

    temp = "cache\\" + temp + ".txt";

    if (_type == OpenType::ONWRITE) {
        cwriter_ = std::make_unique<CacheWriter>(temp);
    }
    else if (_type == OpenType::ONREAD) {
        creader_ = std::make_unique<CacheReader>(temp);
    }
}

bool Cacher::isCached(const std::string &_filename) noexcept {
    std::string   temp{ "cache\\" + _filename + ".txt" };
    std::ifstream fcheck { _filename };

    return fcheck.is_open();
}
