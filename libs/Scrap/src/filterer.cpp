#include "filterer.hpp"

std::vector<std::string> Filterer::filter(const std::any                 &_any, 
                                          const std::vector<std::string> &_filters) {
    auto filtered { p_filterer_->filter(_any, _filters) };
    if (filtered.empty()) {
        excp(Cause::BADFILTER);
    }

    return filtered;
}
