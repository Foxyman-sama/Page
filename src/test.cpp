#include "test.hpp"

bool test() noexcept {
    system("mkdir test");

    try {
        getElapsedTime();

        for (size_t i { }; i < 5; ++i) {
            PageScraper page { URLS[i].data(), DIRECTORY.data(),  "" };
        }

        std::cout << "TEST 1 PASSED!\n";

        getElapsedTime();

        return true;
    }
    catch (const std::exception &e) {
        std::cerr << "TEST 1 FAILED!\n";
        std::cerr << e.what() << '\n\n';

        getElapsedTime();

        return false;
    }
}
bool test2() noexcept {
    try {       
        getElapsedTime();

        for (size_t i { }; i < 5; ++i) {
            PageScraper page { URLS[i].data(), DIRECTORY.data(), FORMATS[i].data() };
        }

        std::cout << "TEST 2 PASSED!\n";  
        
        getElapsedTime();

        return true;
    }
    catch (const std::exception &e) {
        std::cerr << "TEST 2 FAILED!\n";
        std::cerr << e.what() << '\n\n';  
        
        getElapsedTime();

        return false;
    }  
}
void getElapsedTime() noexcept {
    static bool is_end { false };
    static auto start { std::chrono::steady_clock::now() };
    static auto end { std::chrono::steady_clock::now() };

    if (!is_end) {
        start  = std::chrono::steady_clock::now();
        is_end = true;
    }
    else {
        end    = std::chrono::steady_clock::now();
        is_end = false;

        std::cout << "Elapsed time: " << std::chrono::duration<double, std::milli>(end - start).count() / 1000
            << " seconds." << '\n' << '\n';        
    }
    
}
