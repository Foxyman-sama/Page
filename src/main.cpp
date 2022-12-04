#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"
#include "output.hpp"
#include "checker.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    system("mkdir download");

    Connector connector { };

    if (!connector.connect("https://habr.com/ru/company/jugru/blog/506104/")) {
        std::cerr << "Get answer problem. Try in another time.\n";

        system("pause");

        return -1;
    }

    Parser parser { std::regex { "(https|http)[^\"]+(.png|.jpg|-rj)[^\"|^?]*" } };

    if (!parser.parse(connector.getAnswer())) {
        std::cerr << "Get parser problem. Try in another time.\n";

        system("pause");

        return -2;
    }

    Formater   formater { parser.getParsed() };
    auto       formated_vector { formater.getFormated() };
    Checker    checker { "download" };
    Downloader downloader { };

    checker.check(formated_vector);

    for (auto &&el : formated_vector) {
        Output output { formated_vector };

        downloader.download(el);
    }

    system("pause");
    system("cls");
    system("pause");
}