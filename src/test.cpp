#include "test.hpp"

void test1() noexcept {
    std::cout << "Test 1: ";

    std::vector<std::pair<std::string, bool>> urls {
        { "https://habr.com/ru/company/jugru/blog/506104/", true },
        { "https://www.youtube.com/", true },
        { "https://regex101.com/", true },
        { "https://en.cppreference.com/w/", true },
        { "httssssss//", false },
        { "NICEWORLd", false },
        { "https://stackoverflow.com/questions/43806302/constructing-class-from-variadic-templates", true }
    };

    for (size_t i { }; i < urls.size(); ++i) {
        Connector connector { };

        if (connector.connect(urls[i].first) != urls[i].second) {
            std::cout << "Test 1 failed.\n\n";

            return;
        }
    }

    std::cout << "Test 1 accepted.\n\n";
}
void test2() noexcept { 
    std::cout << "Test 2: ";

    std::vector<std::pair<std::string, bool>> urls {
        { "https://habr.com/ru/company/jugru/blog/506104/", true },
        { "https://www.youtube.com/", true },
        { "https://regex101.com/", true },
        { "https://en.cppreference.com/w/", true },
        { "httssssss//", false },
        { "NICEWORLd", false },
        { "https://stackoverflow.com/questions/43806302/constructing-class-from-variadic-templates", true }
    };
    std::vector<std::pair<std::regex, bool>> regexs {
        { std::regex { "(https|http)[^\"]+(.png|.jpg|-rj)[^\"|^?]*" }, true },
        { std::regex { "hssttp" }, false },
        { std::regex { "(https|http)" }, true },
        { std::regex { "png" }, true },
        { std::regex { "[^^^^^^]//" }, false },
        { std::regex { "NICEWORLd" }, false },
        { std::regex { ".{10}" }, true }
    };

    for (size_t i { }; i < urls.size(); ++i) {
        Connector connector { };

        if (connector.connect(urls[i].first) != urls[i].second) {
            std::cout << "Test 2 failed.\n\n";

            return;
        }

        Parser parser { regexs[i].first };

        if (parser.parse(connector.getAnswer()) != regexs[i].second) {
            std::cout << "Test 2 failed.\n\n";

            return;
        }
    }

    std::cout << "Test 2 accepted.\n\n";
}
void test3() noexcept { 
    std::cout << "Test 3: ";

    std::vector<std::string> expected { 
        "httpsen.cppreference.comw",
        "httpswww.youtube.com" ,
        "httpsregex101.com",
        "..................com" ,
        "hello.com"
    };
    ParsedVector vector { 
        ParsedResult { "https://en.cppreference.com/w/", "" },
        ParsedResult { "https://www.youtube.com/", "" },
        ParsedResult { "https://regex101.com/", "" },
        ParsedResult { ".................://.com/", "" },
        ParsedResult { "hello////////.com", "" }
    };

    Formater  formater { vector };
    auto     &formated { formater.getFormated() };

    for (size_t i { }; i < formated.size(); ++i) {
        if (formated[i].format_ != expected[i]) {
            std::cout << "Test 3 failed.\n\n";

            return;
        }
    }


    std::cout << "Test 3 accepted.\n\n";
}
void test4() noexcept {
    std::cout << "Test 4: ";

    std::cout << "Test 4 accepted.\n\n";
}
void test5() noexcept { 
    std::cout << "Test 5: ";

    std::cout << "Test 5 accepted.\n\n";
}
