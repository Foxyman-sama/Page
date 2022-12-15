#include "errorcatcher.hpp"

ErrorCatcher::ErrorCatcher(Status             _status,
                           const std::string &_funcname) noexcept {
    error_msg_ = "[" + _funcname + "]: ";

    if (_status == Status::CACHE_ERROR) {
        error_msg_ += "CACHE_ERROR";
    }
}
