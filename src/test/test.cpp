#include "test.hpp"

void test() {
    constexpr std::array<std::string_view, 5> URLS {
        "https://www.youtube.com/@tazik29",
        "https://habr.com/ru/post/150041/",
        "https://hard.rozetka.com.ua/ua/kingston_sa400s37_240g/p14606570/",
        "https://ru.pinterest.com/pin/667447607293043874/",
        "https://www.instagram.com/cristiano/"
    };
    std::filesystem::path                     path { 
        "E:\\Projects\\Visual Studio\\PageScraper\\bin\\x86-debug\\download"
    };
    auto                                      check { [&]() {
        std::filesystem::directory_iterator it { path };
        size_t                              count { };

        for (auto &&el : it) {
            ++count;
        }

        std::ifstream reader { path.string() + "\\index.txt" };
        size_t        index_size { };

        reader >> index_size;

        if (index_size != count - 1) {
            printStatus("error");

            return false;
        }

        return true;
    } };

    for (size_t i { }; i < URLS.size(); ++i) {
        std::filesystem::remove_all(path);

        system("if not exist download mkdir download");

        std::string answer { scrap::connect(URLS[i].data()) };

        scrap::prepare(answer);

        auto parsed { scrap::parse(answer) };

        scrap::format(parsed);
        scrap::download(parsed);

        assert(check() == true);

        system("cls");
    }

    std::filesystem::remove_all(path);

    printStatus("passed");
}
