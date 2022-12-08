#include "stringmanipulator.hpp"

void StringManipulator::deleteSymbols(std::string             &_str,
                                      const std::vector<char> &_symbols) noexcept {
    std::erase_if(_str, [&](char _ch) {
        for (size_t i { }; i < _symbols.size(); ++i) {
            if (_ch == _symbols[i]) {
                return true;
            }
        }

        return false;
    });
}
void StringManipulator::replace(std::string       &_str,
                                const std::string &_current,
                                const std::string &_new) noexcept {
    while (true) {
        auto pos { _str.find(_current) };

        if (pos == std::string::npos) {
            break;
        }

        _str.replace(pos, _current.size(), _new);
    }
}
