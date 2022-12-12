#include "cachereader.hpp"

bool CacheReader::read(ParsedVector &_parsed) noexcept {
	std::string temp { };

	while (std::getline(fin_, temp)) {
		_parsed.emplace_back(temp, "");

		if ((fin_.fail()) || (fin_.bad())) {
			return false;
		}
	}

	return true;
}
