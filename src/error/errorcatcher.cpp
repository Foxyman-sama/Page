#include "errorcatcher.hpp"

ErrorCatcher::ErrorCatcher(Status             _status,
                           const std::string &_funcname,
                           size_t             _line) noexcept {
    error_msg_ = "\n[" + _funcname + ", " + std::to_string(_line) + "]: ";

    if (_status == Status::CACHE_ERROR) {
        error_msg_ += "CACHE_ERROR";
    }
    else if (_status == Status::CONNECTION_ERROR) {
        error_msg_ += "CONNECTION_ERROR";
    }
    else if (_status == Status::PREPARE_ERROR) {
        error_msg_ += "PREPARE_ERROR";
    }
    else if (_status == Status::PARSE_ERROR) {
        error_msg_ += "PARSE_ERROR";
    }
    else if (_status == Status::FORMATER_ERROR) {
        error_msg_ += "FORMATER_ERROR";
    }
    else if (_status == Status::INDEXER_ERROR) {
        error_msg_ += "INDEXER_ERROR";
    }
    else if (_status == Status::DOWNLOAD_ERROR) {
        error_msg_ += "DOWNLOAD_ERROR";
    }

    error_msg_ += '\n';
}
