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

void Cacher::read(ParsedVector &_parsed) noexcept {
    std::vector<std::string> temp { };

    creader_->read(temp);

    for (size_t i { }; i < temp.size(); ++i) {
        _parsed.emplace_back(temp[i], "");
    }
}
void Cacher::write(ParsedVector &_parsed) noexcept { 
    for (size_t i { }; i < _parsed.size(); ++i) {
        cwriter_->write(_parsed[i].url_);
    }
}
