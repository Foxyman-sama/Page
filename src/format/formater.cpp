#include "formater.hpp"

void Formater::format(ParsedVector &_parsed) noexcept {
    size_t size { _parsed.size() };

    for (size_t i { }; i < size; ++i) {
        if (_parsed[i].url_.find("png/")) {
            StringManipulator::replace(_parsed[i].url_, "png/", "png");
        }
    }
    for (size_t i { }; i < size; ++i) {
        _parsed[i].format_ = _parsed[i].url_;

        StringManipulator::deleteSymbols(_parsed[i].format_);     
        
        if (_parsed[i].url_.find("-rj") != std::string::npos) {
            _parsed[i].format_.append(".png");
        }
        else if (_parsed[i].url_.find("-mo") != std::string::npos) {
            _parsed[i].format_.append(".png");
        }
    }
}