#include "formater.hpp"

std::string Formater::createName(const std::string &_name) noexcept {
    std::string temp { _name };

    std::erase_if(temp, [&](char _ch) {
        return _ch == ':'  ||
               _ch == '\\' ||
               _ch == '/'  ||
               _ch == '?'  ||
               _ch == '&';
    });

    if (temp.find("rj")) {
        temp = temp + ".png";
    }

    return temp;
}

void Formater::format() noexcept {
    size_t size { parsed_.size() };

    for (size_t i { }; i < size; ++i) {
        if (parsed_[i].url_.find("\\u002F")) {
            replace(parsed_[i].url_, "\\u002F", "/");
        }
        if (parsed_[i].url_.find("\\/")) {
            replace(parsed_[i].url_, "\\/", "/");
        }
        if (parsed_[i].url_.find("\\")) {
            replace(parsed_[i].url_, "\\", "/");
        }
    }
    for (size_t i { }; i < size; ++i) {
        parsed_[i].format_ = createName(parsed_[i].url_);
    }
}

void Formater::replace(std::string       &_string,
                       const std::string  _current,
                       const std::string  _new) noexcept {
    while (true) {
        auto pos { _string.find(_current) };

        if (pos == std::string::npos) {
            break;
        }

        _string.replace(pos, _current.size(), _new);
    }
}
