#ifndef EXTRACTOR_HPP
#define EXTRACTOR_HPP

#include "interface/ibaseextractor.hpp"
#include "scrapexception.hpp"

template
class SCRAP_API std::shared_ptr<IBaseExtractor>;

// @brief Class used to extract information
class SCRAP_API Extractor {
private:
    std::shared_ptr<IBaseExtractor> p_extractor_;

public:
    Extractor(const std::shared_ptr<IBaseExtractor> &_p_derived) noexcept 
        : p_extractor_ { _p_derived } { };

    // @brief Used to get specific information
    // @param _p_str    - pointer to string
    // @param _begin    - first value in sequence
    // @param _end      - last value in sequence
    // @param _offset   - offset from the end
    // @param _max_size - max string`s size
    // @return Extracted information
    std::vector<std::string> extract(StringPtr         &_p_str,
                                     const std::string &_begin,
                                     const std::string &_end,
                                     int				_offset   = 0,
                                     size_t             _max_size = UINT_MAX);

    void setStrategy(const std::shared_ptr<IBaseExtractor> &_p_derived) noexcept {
        p_extractor_ = _p_derived;
    }
};

#endif 