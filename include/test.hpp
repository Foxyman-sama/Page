#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#include "pagescraper.hpp"

constexpr std::string_view URLS[] {
    "https://www.youtube.com/",
    "https://www.youtube.com/@poseidonskiy240",
    "https://hard.rozetka.com.ua/ua/kingston_sa400s37_240g/p14606570/",
    "https://habr.com/ru/post/150041/",
    "https://www.flaticon.com/ru/stickers-pack/ronnie-the-bunny-plant-care"
};
constexpr std::string_view FORMATS[] {
    "png",
    "rj|png|jpg",
    "rj",
    "",
    "jpg"
};

bool test() noexcept;
bool test2() noexcept;

#endif 