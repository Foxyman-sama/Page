#include "test.hpp"

void test() { 
    constexpr std::array<std::string_view, 3> URLS {
        "https://www.youtube.com/@tazik29",
        "https://habr.com/ru/post/150041/",
        "https://hard.rozetka.com.ua/ua/kingston_sa400s37_240g/p14606570/"
    };

    std::filesystem::path path { "download" };

    for (size_t i { }; i < URLS.size(); ++i) {
        std::string answer { user::connect(URLS[i].data()) };

        user::prepare(answer);

        auto parsed { user::parse(answer) };

        user::download(parsed);
    }
}
