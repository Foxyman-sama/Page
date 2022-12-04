#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include <chrono>
#include "parsedresult.hpp"

class Output {
private:
    static double total_time_;
    static size_t new_pos_;

private:
    std::chrono::steady_clock::time_point start_;
    std::chrono::steady_clock::time_point end_;

public:
    explicit Output(const ParsedVector &_parsed) noexcept;
    ~Output() noexcept;
};

#endif 