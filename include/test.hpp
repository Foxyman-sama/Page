#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <chrono>
#include <vector>
#include "connector.hpp"
#include "parser.hpp"

struct Time {
private:
    std::chrono::steady_clock::time_point start_;
    std::chrono::steady_clock::time_point end_;

public:
    Time() noexcept {
        start_ = std::chrono::steady_clock::now();
    }
    ~Time() noexcept {
        end_ = std::chrono::steady_clock::now();
        std::cout << "Time elapsed: " 
                  << std::chrono::duration<double, std::milli>(end_ - start_) << '\n' << '\n';
    }
};
struct UrlNormalChecker {
public:
    std::string url_;
    bool        normal_;

public:
    UrlNormalChecker(const std::string &_url,
                     bool               _normal) :
        url_ { _url },
        normal_ { _normal } { }
};
struct RegexNormalChecker {
public:
    std::regex  regular_;
    bool        normal_;

public:
    RegexNormalChecker(const std::regex &_regular,
                       bool              _normal) :
        regular_ { _regular },
        normal_ { _normal } { }
};

void test1() noexcept;
void test2() noexcept;
void test3() noexcept;
void test4() noexcept;
void test5() noexcept;

#endif 