#include "test.hpp"

void test1() noexcept {
    std::cout << "Test 1: ";

    std::vector<UrlNormalChecker> urls {
        { "https://www.youtube.com/", true },
        { "https://rozetka.com.ua/ua/signin/", true },
        { "https://habr.com/ru/post/150041/", true },
        { "https://grdgdg.dot", false },
        { "https://www.https://n-my-fundamentalnye-algoritm/", false }
    };

    Time time { };

    for (size_t i { }; i < 5; ++i) {
        Connector connector { };

        if (connector.connect(urls[i].url_) != urls[i].normal_) {
            std::cerr << "Test 1 failed.\n";

            return;
        }
    }

    std::cout << "Test 1 accepted.\n";
}
void test2() noexcept { 
    std::cout << "Test 2: ";

    std::vector<UrlNormalChecker> urls {
        { "https://www.youtube.com/", true },
        { "https://rozetka.com.ua/ua/signin/", true },
        { "https://habr.com/ru/post/150041/", true },
        { "https://grdgdg.dot", false },
        { "https://www.https://n-my-fundamentalnye-algoritm/", false }
    };
    std::vector<RegexNormalChecker> regexs {
        { std::regex { "https://www.youtube.com/" }, true },
        { std::regex { "https://www.youtube.com/" }, true },
        { std::regex { "https://www.youtube.com/" }, true },
        { std::regex { "https://www.youtube.com/" }, true },
        { std::regex { "https://www.youtube.com/" }, true }
    };
    std::vector<std::string> formats {
        ".png", ".jpg", "-rj", "fds", "HELLO"
    };

    Time time { };

    for (size_t i { }; i < 5; ++i) {
        Connector connector { };
        Parser    parser { regexs[i].regular_ };

        if (connector.connect(urls[i].url_) != urls[i].normal_) {
            std::cerr << "Test 2 failed.\n";

            return;
        }

        if (parser.parse(connector.getAnswer(), formats[i]) != regexs[i].normal_) {
            std::cerr << "Test 2 failed.\n";

            return;
        }
    }   

    std::cout << "Test 2 accepted.\n";
}
void test3() noexcept { }
void test4() noexcept { }
void test5() noexcept { }
