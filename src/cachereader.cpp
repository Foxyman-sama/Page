#include "cachereader.hpp"

bool CacheReader::read(std::vector<std::string> &_vector) noexcept {
	std::string temp { };

	while (std::getline(fin_, temp)) {
		_vector.emplace_back(temp);

		if ((fin_.fail()) || (fin_.bad())) {
			return false;
		}
	}

	return true;
}
