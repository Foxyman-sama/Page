#ifndef IBASEEXTRACTOR_HPP
#define IBASEEXTRACTOR_HPP

#include <memory>
#include <string>
#include <vector>
#include "dll.hpp"

using StringPtr = std::shared_ptr<std::string>;

class IBaseExtractor {
public:
	virtual std::vector<std::string> extract(StringPtr		   &_p_str,
											 const std::string &_begin,
											 const std::string &_end,
											 int				_offset   = 0,
											 size_t				_max_size = UINT_MAX) noexcept = 0;
};

#endif 