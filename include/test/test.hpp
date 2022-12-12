#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cassert>
#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"
#include "checker.hpp"
#include "print.hpp"

constexpr size_t MAX_TRY_COUNT { 5 };

struct ElapsedTime {
private:
    std::string                           title_;
    std::chrono::steady_clock::time_point start_;
    std::chrono::steady_clock::time_point end_;

public:
    ElapsedTime(const std::string &_title) noexcept :
        title_ { '\n' + _title } {
        start_ = std::chrono::steady_clock::now();
    }
    ~ElapsedTime() noexcept {
        end_ = std::chrono::steady_clock::now();
        std::cout << title_ << ": " 
                  << std::chrono::duration<double, std::milli>(end_ - start_).count() / 1000
                  << " seconds.\n";
    }
};
  
static std::vector<std::string> urls { };
static std::vector<std::regex>  regexs { };
static std::vector<std::string> expecteds { };
static std::vector<std::string> images { };

template <typename T>
static void initVector(std::vector<T>    &_vector,
                       const std::string &_filename) noexcept { 
    std::ifstream fin {  };
    std::string   temp { };

    fin.open(_filename);

    assert(fin.is_open() == true);

    while (std::getline(fin, temp)) {
        _vector.emplace_back(T {temp});
    }

    fin.close();
}

void testConfiguration() noexcept;
void test1() noexcept;
void test2() noexcept;
void test3() noexcept;
void test4() noexcept;
void test5() noexcept;

#endif 