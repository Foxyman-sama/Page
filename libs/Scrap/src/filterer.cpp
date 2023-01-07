#include "filterer.hpp"

std::vector<std::string> Filterer::filter(const std::any    &_any, 
                                          const std::string &_filter) {
    auto filtered { p_filterer_->filter(_any, _filter) };
    if (filtered.empty()) {
        excp(Cause::BADFILTER);
    }

    return filtered;
}
