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
void StringManipulator::deleteRangeMatches(std::string       &_str, 
                                           const std::string &_begin, 
                                           const std::string &_end) noexcept {
    while (true) {
        size_t start_pos { _str.find(_begin) };
        size_t end_pos { _str.find(_end, start_pos) };

        if ((start_pos == std::string::npos) ||
            (end_pos == std::string::npos)) {
            break;
        }

        _str.erase(start_pos, end_pos - start_pos + _end.size());
    }
}
void StringManipulator::replace(std::string       &_str,
                                const std::string &_current,
                                const std::string &_new) noexcept {
    while (true) {
        size_t pos { _str.find(_current) };

        if (pos == std::string::npos) {
            break;
        }

        _str.replace(pos, _current.size(), _new);
    }
}
