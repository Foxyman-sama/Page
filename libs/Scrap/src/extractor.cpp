#include "extractor.hpp"

std::vector<std::string> Extractor::extract(StringPtr         &_p_str,
                                            const std::string &_begin,
                                            const std::string &_end,
                                            int                _offset,
                                            size_t             _max_size) {
    std::vector<std::string> return_result {
        p_extractor_->extract(_p_str, _begin, _end, _offset, _max_size) 
    };
    if (return_result.empty()) {
        excp(Cause::BADEXTRACT);
    }

    return return_result;
}
