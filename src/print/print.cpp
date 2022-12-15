#include "print.hpp"

Print::Print(size_t _size) noexcept {
    system("cls");

    total_time_ = 0.;
    new_pos_    = 0;
    start_      = std::chrono::steady_clock::now();
    counter_    = 0;

    if (_size < 10) {
        divider_ = 10 / _size;
    } 
    else {
        divider_ = std::floor((static_cast<double>(_size) * 10) / 100);
    }

    std::cout << '[';

    for (size_t i { }; i < 10; ++i) {
        std::cout << '*';
    }

    std::cout << ']';
}
Print::~Print() noexcept {
    end_ = std::chrono::steady_clock::now();

    double seconds { std::chrono::duration<double, std::milli>(end_ - start_).count() / 1000 };

    std::cout.width(25);
    std::cout << "Total time elapsed: " << seconds << " seconds.\n";
}

void Print::update() noexcept {
    system("cls");

    std::cout << '[';

    for (size_t i { }; i < new_pos_; ++i) {
        std::cout << '#';
    }
    for (size_t i { new_pos_ }; i < 10; ++i) {
        std::cout << '*';
    }

    std::cout << ']';
}

void Print::print() noexcept {
    if (!(++counter_ % divider_) &&
        (new_pos_ != 10)) {
        ++new_pos_;

        update();
    }
}
