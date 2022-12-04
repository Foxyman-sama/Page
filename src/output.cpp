#include "output.hpp"

double Output::total_time_ { };
size_t Output::new_pos_ { };

Output::Output(const ParsedVector &_parsed) noexcept { 
	system("cls");

	size_t size { _parsed.size() };

	start_ = std::chrono::steady_clock::now();

	for (size_t i { new_pos_ }; i < size; ++i) {
		std::cout << ' ' << _parsed[i].url_ << '\n';
	}

	++new_pos_;
}

Output::~Output() noexcept {
	end_ = std::chrono::steady_clock::now();

	double seconds { std::chrono::duration<double, std::milli>(end_ - start_).count() / 1000 };
	
	std::cout.width(25);
	std::cout << "Time elapsed: " << seconds << " seconds.\n";

	total_time_ += seconds;

	std::cout.width(25);
	std::cout << "Total time elapsed: " << total_time_ << " seconds.\n";
}
