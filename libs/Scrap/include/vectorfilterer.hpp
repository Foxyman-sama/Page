#ifndef VECTORFILTERER_HPP
#define VECTORFILTERER_HPP

#include "interface/ibasefilterer.hpp"
#include "dll.hpp"

class SCRAP_API VectorFilterer 
    : public IBaseFilterer {
public:
    virtual std::vector<std::string> filter(const std::any    &_any,
                                            const std::string &_filter) noexcept override;
};

#endif 