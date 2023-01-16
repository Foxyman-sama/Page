#ifndef XMLFILTERER_HPP
#define XMLFILTERER_HPP

#include <tinyxml2.h>
#include "interface/ibasefilterer.hpp"

class SCRAP_API XMLFilterer 
    : public IBaseFilterer {
private:
    tinyxml2::XMLDocument xmldoc_;

public:
    virtual std::vector<std::string> filter(const std::any                 &_any,
                                            const std::vector<std::string> &_filters) noexcept override;
};

#endif 