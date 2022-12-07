#define TESTMODE1

#ifndef TESTMODE

#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"
#include "output.hpp"
#include "checker.hpp"
#include "indexer.hpp"

constexpr size_t MAX_TRY_COUNT { 5 };

void scraping(const std::string &_url,
              const std::string &_formats) noexcept;

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, "");   

    std::string url { };
    std::string formats { };

    if (_argc == 3) {
        url     = _p_argv[1];
        formats = _p_argv[2];
    }
    else if (_argc == 2) {
        url     = _p_argv[1];
        formats = ".png|.jpg|-rj";
    }
    else {
        std::cout << "¬ведите сайт:    ";
        std::getline(std::cin, url);

        std::cout << "¬ведите форматы: ";
        std::getline(std::cin, formats);
    }

    scraping(url, formats);

    system("pause");
}

void scraping(const std::string &_url, 
              const std::string &_formats) noexcept {
    system("mkdir download");
    system("cls");

    Connector connector { };

    if (!connector.connect(_url)) {
        std::cerr << "Get answer problem. Try in another time.\n";

        system("pause");

        return;
    }

    Parser parser { std::regex { "(https|http)[^\"]+(" + _formats + ")[^\"|^?]*" } };

    if (!parser.parse(connector.getAnswer())) {
        std::cerr << "Get parser problem. Try in another time.\n";

        system("pause");

        return;
    }

    Formater   formater { parser.getParsed() };
    auto       formated_vector { formater.getFormated() };
    Downloader downloader { };
    Checker    checker { "download" };

    checker.check(formated_vector);

    Indexer indexer { "download/index.txt", formated_vector.size() };

    for (auto &&el : formated_vector) {
        Output output { formated_vector };

        indexer.indexing(el.format_);

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

                    return;
                }
            }
        }
    }

    system("pause");
    system("cls");
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

