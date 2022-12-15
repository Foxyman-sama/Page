#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <chrono>
#include "parsedresult.hpp"

class Print {
private:
    using TimePoint = std::chrono::steady_clock::time_point;

private:
    double    total_time_;
    size_t    new_pos_;
    TimePoint start_;
    TimePoint end_;
    size_t    counter_;
    size_t    divider_;

private:
    void update() noexcept;

public:
     Print(size_t _size) noexcept;
    ~Print() noexcept;

    void print() noexcept;
};

#endif 