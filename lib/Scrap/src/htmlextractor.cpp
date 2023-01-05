#include "htmlextractor.hpp"

std::vector<std::string> HTMLExtractor::extract(StringPtr         &_p_str,
                                                const std::string &_begin,
                                                const std::string &_end,
                                                int				   _offset) noexcept {
    std::vector<std::string> matches { };
    matches.reserve(128);

    size_t fpos { _p_str->find(_begin) };
    size_t lpos { _p_str->find(_end, fpos + _begin.size()) };
    while ((fpos != std::string::npos) && (fpos != lpos)) {
        std::string temp { _p_str->begin() + fpos, 
                           _p_str->begin() + lpos + _end.size() + _offset };
        matches.emplace_back(temp);
        fpos = _p_str->find(_begin, lpos + _end.size());
        lpos = _p_str->find(_end, fpos + _begin.size());
    }

    return matches;
}
