#include "formater.hpp"

void Formater::format(ParsedVector &_parsed) noexcept {
    size_t                   size { _parsed.size() };
    std::vector<std::string> bsymbols {
        "\\u002F", "\\/", "\\\\/", "\\"
        // What kind symbols need delete
    }; 
    size_t                   bs_size { bsymbols.size() };

    for (size_t i { }; i < size; ++i) {
        for (size_t j { }; j < bs_size; ++j) {
            if (_parsed[i].url_.find(bsymbols[j])) {
                StringManipulator::replace(_parsed[i].url_, bsymbols[j], "/");
            }
        }

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