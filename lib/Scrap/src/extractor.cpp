#include "extractor.hpp"

std::vector<std::string> Extractor::extract(StringPtr         &_p_str,
                                            const std::string &_begin,
                                            const std::string &_end,
                                            int                _offset) {
    std::vector<std::string> return_result {
        p_extractor_->extract(_p_str, _begin, _end, _offset) 
    };
    if (return_result.empty()) {
        excp(Cause::BADEXTRACT);
    }

    return return_result;
}
