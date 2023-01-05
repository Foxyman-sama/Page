#ifndef FILTERER_HPP
#define FILTERER_HPP

#include <memory>
#include "interface/ibasefilterer.hpp"
#include "scrapexception.hpp"
#include "dll.hpp"

template
class SCRAP_API std::shared_ptr<IBaseFilterer>;

// @brief Class used to filter information.
class SCRAP_API Filterer {
private:
    std::shared_ptr<IBaseFilterer> p_filterer_;

public:
    Filterer(std::shared_ptr<IBaseFilterer> &_p_derived) noexcept 
        : p_filterer_ { _p_derived } { }

    // @brief Used to format information 
    // @brief If you want use XMLFilter, you need use only C-style string!
    // @param _any    - changes depending on the input value
    // @param _filter - set filter
    // @return Filtered information
    std::vector<std::string> filter(const std::any    &_any,
                                    const std::string &_filter);
};

#endif 