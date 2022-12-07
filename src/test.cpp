#include "test.hpp"
void testConfiguration() noexcept { 
    initVector<std::string>(urls, "test/urls.txt");
    initVector<std::regex>(regexs, "test/regexs.txt");
    initVector<std::string>(expecteds, "test/expecteds.txt");
    initVector<std::string>(images, "test/images.txt");
}
void test1() noexcept {
    std::cout << "Test 1: ";

    for (size_t i { }; i < urls.size(); ++i) {
        Connector   connector { };
        ElapsedTime time { "Test 1 [connect]" };

        assert(connector.connect(urls[i]) == true);
    }

    std::cout << "Test 1 OK.\n\n";
}
void test2() noexcept { 
    std::cout << "Test 2: ";

    for (size_t i { }; i < urls.size(); ++i) {
        Connector connector { };

        {
            ElapsedTime time { "Test 2 [connect]" };

            assert(connector.connect(urls[i]) == true);
        }
        {
            for (size_t j { }; j < regexs.size(); ++j) {
                Parser      parser { regexs[j] };
                ElapsedTime time { "Test 2 [parse]" };

                assert(parser.parse(connector.getAnswer()) == true);
            }
        }
    }

    std::cout << "Test 2 OK.\n\n";
}
void test3() noexcept { 
    std::cout << "Test 3: ";

    ParsedVector  temp_vector { urls.begin(), urls.end() };
    Formater      formater { temp_vector };
    auto         &formated { formater.getFormated() };

    for (size_t i { }; i < formated.size(); ++i) {
        assert(formated[i].format_ == expecteds[i]);
    }

    std::cout << "Test 3 OK.\n\n";
}
void test4() noexcept {
    std::cout << "Test 4: ";

    ParsedVector temp_vector { };
    Downloader   downloader { };

    for (size_t i { }; i < images.size(); ++i) {
        temp_vector.emplace_back(images[i], "");
    }
    for (size_t i { }; i < temp_vector.size(); ++i) {
        ElapsedTime time { "Test 4 [download]" };
        assert(downloader.download(temp_vector[i]) == true);
    }

    std::cout << "Test 4 OK.\n\n";
}
void test5() noexcept { 
    std::cout << "Test 5: ";

    ElapsedTime time { "Test 5 [main program]" };

    system("mkdir download");

    Connector connector { };
    Parser parser { std::regex { "(https|http)[^\"]+(.png|.jpg|-rj)[^\"|^?]*" } };

    assert(connector.connect("https://habr.com/ru/company/jugru/blog/506104/") == true);
    assert(parser.parse(connector.getAnswer()) == true);

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

                assert(++try_count != 5);
            }
        }
    }

    std::cout << "Test 5 OK.\n\n";
}
