#include "test.hpp"

bool test() noexcept {
    try {
        for (size_t i { }; i < 5; ++i) {
            PageScraper page { URLS[i].data(), "" };
        }

        std::cout << "TEST 1 PASSED!\n";
        return true;
    }
    catch (const std::exception &e) {
        std::cerr << "TEST 1 FAILED!\n";
        std::cerr << e.what() << '\n\n';

        return false;
    }
}
bool test2() noexcept {
    try {
        for (size_t i { }; i < 5; ++i) {
            PageScraper page { URLS[i].data(), FORMATS[i].data() };
        }

        std::cout << "TEST 2 PASSED!\n";
        return true;
    }
    catch (const std::exception &e) {
        std::cerr << "TEST 2 FAILED!\n";
        std::cerr << e.what() << '\n\n';

        return false;
    }  
}