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

    std::cout << "Test 5 OK.\n\n";
}
