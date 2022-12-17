#ifndef USERFUNCTIONS_HPP
#define USERFUNCTIONS_HPP

#include "headers.hpp"

namespace scrap {
    constexpr std::string_view FORMATS { ".png|.jpg|-rj|-mo|.ico|8fd12b" };

    std::string  connect(const std::string &_url);
    ParsedVector parse(const std::string &_answer,
                       const std::string &_formats = FORMATS.data());

    void start();
    void scraping(std::string       &_url);
    void prepare(std::string &_answer) noexcept;
    void format(ParsedVector &_parsed);
    void download(ParsedVector &_parsed);
}

#endif 