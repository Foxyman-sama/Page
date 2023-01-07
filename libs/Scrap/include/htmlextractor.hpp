#ifndef HTMLEXTRACTOR_HPP
#define HTMLEXTRACTOR_HPP

#include <regex>
#include "interface/ibaseextractor.hpp"
#include "dll.hpp"

class SCRAP_API HTMLExtractor final
    : public IBaseExtractor {
public:
    virtual std::vector<std::string> extract(StringPtr         &_p_str,
                                             const std::string &_begin,
                                             const std::string &_end,
                                             int				_offset = 0) noexcept override;
};

#endif 