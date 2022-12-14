#include "print.hpp"

double Print::total_time_ { };
size_t Print::new_pos_ { };

Print::Print(const ParsedVector &_parsed) noexcept :
    parsed_ { _parsed } {
    system("cls");
    start_ = std::chrono::steady_clock::now();
}
Print::~Print() noexcept {
    end_ = std::chrono::steady_clock::now();

    double seconds { std::chrono::duration<double, std::milli>(end_ - start_).count() / 1000 };

    std::cout.width(25);
    std::cout << "Total time elapsed: " << seconds << " seconds.\n";
}

void Print::print() noexcept {
    system("cls");

    for (size_t i { new_pos_ }; i < parsed_.size(); ++i) {
        std::cout.width(5);
        std::cout << i << ' ' << parsed_[i].url_ << '\n';
    }

    ++new_pos_;
}
