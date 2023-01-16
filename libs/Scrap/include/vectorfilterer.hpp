#ifndef VECTORFILTERER_HPP
#define VECTORFILTERER_HPP

#include "interface/ibasefilterer.hpp"

class SCRAP_API VectorFilterer 
    : public IBaseFilterer {
public:
    virtual std::vector<std::string> filter(const std::any                 &_any,
                                            const std::vector<std::string> &_filters) noexcept override;
};

#endif 