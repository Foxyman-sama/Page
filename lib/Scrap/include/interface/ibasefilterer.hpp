#ifndef IBASEFILTERER_HPP
#define IBASEFILTERER_HPP

#include <vector>
#include <string>
#include <any>

class IBaseFilterer {
public:
    virtual std::vector<std::string> filter(const std::any    &_any,
                                            const std::string &_filter) noexcept = 0;
};

#endif 