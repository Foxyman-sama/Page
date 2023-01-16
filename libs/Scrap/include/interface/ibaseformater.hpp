#ifndef IBASEFORMATER_HPP
#define IBASEFORMATER_HPP

#include <memory>
#include <string>
#include "dll.hpp"

using StringPtr = std::shared_ptr<std::string>;

class IBaseFormater {
public:
    virtual size_t format(StringPtr &_p_str) noexcept = 0;
};

#endif 