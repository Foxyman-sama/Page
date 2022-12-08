#define TESTMODE1

#ifndef TESTMODE

#include "userfunctions.hpp"

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

    std::string  temp { _url };
    Cacher       cacher { "cache", temp };
    ParsedVector parsed { };

    if (!cacher.isCached()) {
        std::string answer { user::connect(_url) };

        parsed = user::parse(answer, _formats);

        cacher.write(parsed);
    }
    else {
        parsed = cacher.read();
    }

    user::format(parsed);
    user::download(parsed);

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

