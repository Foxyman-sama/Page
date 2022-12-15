#ifndef ERRORCATHER_HPP
#define ERRORCATHER_HPP

#include <iostream>

#define Throw(_status) throw ErrorCatcher { _status, __func__ };

class ErrorCatcher : public std::exception {
private:
    std::string error_msg_;

public:
    enum class Status {
        CACHE_ERROR,
        CONNECTION_ERROR,
        PREPARE_ERROR,
        FORMATER_ERROR,
        DOWNLOAD_ERROR
    };

public:
    ErrorCatcher(Status             _status,
                 const std::string &_funcname) noexcept;

    virtual const char *what() const override {
        return error_msg_.c_str();
    }
};

#endif 