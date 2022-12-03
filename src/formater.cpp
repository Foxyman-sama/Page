#include "formater.hpp"

void Formater::format() noexcept { 
    auto   format {[&](const std::string &_url) {
        std::string temp { _url };
        size_t      pos { std::erase_if(temp, [&](char _ch) {
            return _ch == ':'  ||
                   _ch == '\\' ||
                   _ch == '/'  ||
                   _ch == '?'  ||
                   _ch == '&';
        }) };

        if (temp.find("rj")) {
            temp = temp + ".png";
        }

        return temp;
    } };
    size_t size { parsed_.size() };

    for (size_t i { }; i < size; ++i) {
        parsed_[i].format_ = format(parsed_[i].url_);
    }
}
