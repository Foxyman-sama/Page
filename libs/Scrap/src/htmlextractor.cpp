#include "htmlextractor.hpp"

std::vector<std::string> HTMLExtractor::extract(StringPtr         &_p_str,
                                                const std::string &_begin,
                                                const std::string &_end,
                                                int				   _offset,
                                                size_t             _max_size) noexcept {
    std::vector<std::string> matches { };
    matches.reserve(256);

    size_t fpos { _p_str->find(_begin) };
    size_t lpos { _p_str->find(_end, fpos + 1) };
    while ((fpos != std::string::npos) && (lpos != std::string::npos)) {
        if ((lpos - fpos) <= _max_size) {
            std::string temp { _p_str->begin() + fpos,
                               _p_str->begin() + lpos + _end.size() + _offset };
            matches.emplace_back(temp);
        }

        fpos = _p_str->find(_begin, fpos + 1);
        lpos = _p_str->find(_end, fpos + 1);
    }

    return matches;
}
