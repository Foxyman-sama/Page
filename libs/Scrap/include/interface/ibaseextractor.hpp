#ifndef IBASEEXTRACTOR_HPP
#define IBASEEXTRACTOR_HPP

#include <memory>
#include <string>
#include <vector>

using StringPtr = std::shared_ptr<std::string>;

class IBaseExtractor {
public:
	virtual std::vector<std::string> extract(StringPtr		   &_p_str,
											 const std::string &_begin,
											 const std::string &_end,
											 int				_offset = 0) noexcept = 0;
};

#endif 