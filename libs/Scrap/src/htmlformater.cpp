#include "htmlformater.hpp"

size_t HTMLFormater::format(StringPtr &_p_str) noexcept {
    size_t counter { };
    std::erase_if(*_p_str, [&](char _ch) {
        ++counter;
        return isspace(_ch);
    });
    for (size_t i { }; i < ENTITYS.size(); ++i) {
        size_t pos { _p_str->find(ENTITYS[i]) };
        while (pos != std::string::npos) {
            _p_str->replace(pos, ENTITYS[i].size(), REPLACEMENTS[i]);
            pos = _p_str->find(ENTITYS[i]);
            ++counter;
        }
    }

    return counter;
}
