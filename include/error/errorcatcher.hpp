#ifndef ERRORCATHER_HPP
#define ERRORCATHER_HPP

#include <iostream>

using Status = ErrorCatcher::Status;

#define Throw(_status) throw ErrorCatcher { _status, __func__ };

class ErrorCatcher : public std::exception {
private:
    Status      status_;
    std::string funcname_;

public:
    enum class Status {
        CACHE_ERROR
    };


public:
    ErrorCatcher(Status             _status,
                 const std::string &_funcname) noexcept;
};

#endif 