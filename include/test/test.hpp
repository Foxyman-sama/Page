#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <array>
#include <cassert>
#include "userfunctions.hpp"

#define printStatus(_is_passed)      \
    std::cout.width(12);             \
    std::cout << __func__ << " - ";  \
    std::cout << _is_passed << '\n';

void test();

#endif 