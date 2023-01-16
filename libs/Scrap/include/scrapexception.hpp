#ifndef SCRAPEXCEPTION_HPP
#define SCRAPEXCEPTION_HPP

#include <exception>
#include <string.h>

#define excp(_cause) \
    throw ScrapException { _cause };

enum class Cause {
    BADREQUEST,
    BADFORMAT,
    BADEXTRACT,
    BADCACHEWRITE,
    BADCACHEREAD,
    BADFILTER,
    BADDOWNLOAD
};

class ScrapException
    : public std::exception {
private:
    char data_[35];

private:
    void setError(const char _error[]) noexcept;

public:
    explicit ScrapException(Cause _cause) noexcept;

    virtual const char *what() const noexcept override {
        return data_;
    }
};

#endif 