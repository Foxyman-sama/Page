#ifndef IBASERECEIVER_HPP
#define IBASERECEIVER_HPP

#include <memory>
#include <string>
#include "dll.hpp"

using StringPtr = std::shared_ptr<std::string>;

class IBaseReceiver {
public:
	virtual StringPtr receive(const std::string &_url) noexcept = 0;
};

#endif 