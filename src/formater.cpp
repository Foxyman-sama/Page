#include "formater.hpp"

void Formater::format(ParsedVector &_parsed) noexcept {
    size_t size { _parsed.size() };

    for (size_t i { }; i < size; ++i) {
        if (_parsed[i].url_.find("\\u002F")) {
            StringManipulator::replace(_parsed[i].url_, "\\u002F", "/");
        }
        if (_parsed[i].url_.find("\\/")) {
            StringManipulator::replace(_parsed[i].url_, "\\/", "/");
        }
        if (_parsed[i].url_.find("\\")) {
            StringManipulator::replace(_parsed[i].url_, "\\", "/");
        }
    }
    for (size_t i { }; i < size; ++i) {
        _parsed[i].format_ = _parsed[i].url_;

        StringManipulator::deleteSymbols(_parsed[i].format_);     
        
        if (_parsed[i].url_.find("rj") != std::string::npos) {
            _parsed[i].format_.append(".png");
        }
    }
}