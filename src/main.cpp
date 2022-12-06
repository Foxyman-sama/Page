#define TESTMODE

#ifndef TESTMODE

#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"
#include "output.hpp"
#include "checker.hpp"

constexpr size_t MAX_TRY_COUNT { 5 };

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

        if (!downloader.download(el)) {
            size_t try_count { };

            while (try_count != MAX_TRY_COUNT) {
                system("cls");

                std::cout << "Try to download: " << el.url_ << '\n';

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                if (downloader.download(el)) {
                    break;
                }
                else if (++try_count == 5) {
                    std::cout << "Can`t download " << el.url_ << '\n';
                    std::cout << "Try later.\n\n";

                    system("pause");

                    return -3;
                }
            }
        }
    }

    system("pause");
    system("cls");
    system("pause");
}

#endif

#ifdef TESTMODE

#include "test.hpp"

int main() {
    setlocale(0, ".UTF8");

    testConfiguration();
    test1();
    test2();
    test3();
    test4();
    test5();

    system("pause");
}

#endif