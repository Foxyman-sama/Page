#define TESTMODE1

#ifndef TESTMODE

#include "userfunctions.hpp"

constexpr std::string_view IMAGE_FORMATS { ".png|.jpg|-rj|-mo|.ico" };

void scraping(std::string       &_url,
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
        formats = IMAGE_FORMATS;
    }
    else {
        std::cout << "¬ведите сайт:    ";
        std::getline(std::cin, url);

        std::cout << "¬ведите форматы: ";
        std::getline(std::cin, formats);

        if ((formats.empty()) || (formats == "image")) {
            formats = IMAGE_FORMATS;
        }
    }

    scraping(url, formats);

    system("pause");
}

void scraping(std::string       &_url, 
              const std::string &_formats) noexcept {
    system("if not exist download mkdir download");
    system("cls");

    ParsedVector parsed { };

    if (!Cacher::isCached(_url)) {
        std::string answer { user::connect(_url) };

        user::prepare(answer);

        parsed = user::parse(answer, _formats);

        Cacher cacher { _url, Cacher::OpenType::ONWRITE };
        cacher.write(parsed);
    }
    else {
        Cacher cacher { _url, Cacher::OpenType::ONREAD };
        cacher.read(parsed);
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

