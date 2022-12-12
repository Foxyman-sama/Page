#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <chrono>
#include "parsedresult.hpp"

class Print {
private:
    static double total_time_;
    static size_t new_pos_;

private:
    std::chrono::steady_clock::time_point start_;
    std::chrono::steady_clock::time_point end_;

public:
    explicit Print(const ParsedVector &_parsed) noexcept;
    ~Print() noexcept;
};

#endif 