#include "../include/scrapexception.hpp"

void ScrapException::setError(const char _error[]) noexcept { 
    memcpy_s(data_, sizeof(data_), _error, strlen(_error) + 1);
}

ScrapException::ScrapException(Cause _cause) noexcept
    : data_ { } {
    if (_cause == Cause::BADREQUEST) {
        setError("\nError #0: Bad request\n");
    }
    else if (_cause == Cause::BADFORMAT) {
        setError("\nError #1: Bad format\n");
    }
    else if (_cause == Cause::BADEXTRACT) {
        setError("\nError #2: Bad extract\n");
    }
    else if (_cause == Cause::BADCACHEWRITE) {
        setError("\nError #3.1: Bad cache write\n");
    }
    else if (_cause == Cause::BADCACHEREAD) {
        setError("\nError #3.2: Bad cache read\n");
    }
    else if (_cause == Cause::BADFILTER) {
        setError("\nError #4: Bad filter\n");
    }
    else if (_cause == Cause::BADDOWNLOAD) {
        setError("\nError #5: Bad download\n");
    }
}
