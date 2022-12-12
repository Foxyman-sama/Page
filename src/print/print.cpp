#include "print.hpp"

double Print::total_time_ { };
size_t Print::new_pos_ { };

Print::Print(const ParsedVector &_parsed) noexcept {
    system("cls");

    size_t size { _parsed.size() };

    start_ = std::chrono::steady_clock::now();

    for (size_t i { new_pos_ }; i < size; ++i) {
        std::cout << ' ' << _parsed[i].url_ << '\n';
    }

    ++new_pos_;
}

Print::~Print() noexcept {
    end_ = std::chrono::steady_clock::now();

    double seconds { std::chrono::duration<double, std::milli>(end_ - start_).count() / 1000 };

    std::cout.width(25);
    std::cout << "Time elapsed: " << seconds << " seconds.\n";

    total_time_ += seconds;

    std::cout.width(25);
    std::cout << "Total time elapsed: " << total_time_ << " seconds.\n";
}
