#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    Connector connector { };

    if (!connector.connect("https://www.youtube.com/")) {
        std::cerr << "Get answer problem. Try in another time.\n";

        system("pause");

        return -1;
    }

    Parser parser { std::regex { "(https|http)[^\"]+(.png|.jpg|-rj)[^\"|^?]*" } };

    if (!parser.parse(connector.getAnswer(), ".png")) {
        std::cerr << "Get parser problem. Try in another time.\n";

        system("pause");

        return -2;
    }

    Formater    formater { parser.getParsed() };
    Downloader  downloader { };
    auto       &formated { formater.getFormated() };
    size_t      size { formated.size() };
    size_t      new_pos { };

    for (auto &&el : formated) {
        system("cls");

        for (size_t i { new_pos }; i < size; ++i) {
            std::cout << formated[i].url_ << '\n';
        }

        downloader.download(el);

        ++new_pos;
    }

    system("cls");
    system("pause");
}