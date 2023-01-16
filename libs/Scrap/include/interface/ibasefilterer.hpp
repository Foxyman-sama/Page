#ifndef IBASEFILTERER_HPP
#define IBASEFILTERER_HPP

#include <vector>
#include <string>
#include <any>
#include <algorithm>
#include "dll.hpp"

class IBaseFilterer {
public:
    virtual std::vector<std::string> filter(const std::any                 &_any,
                                            const std::vector<std::string> &_filters) noexcept = 0;
};

#endif 