#ifndef IBASERECEIVER_HPP
#define IBASERECEIVER_HPP

#include <memory>
#include <string>

using StringPtr = std::shared_ptr<std::string>;

constexpr std::string_view USER_AGENT {
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
    "AppleWebKit/537.36 (KHTML, like Gecko) "
    "Chrome/108.0.0.0 Safari/537.36"
};

class IBaseReceiver {
public:
	virtual StringPtr sendRequest(const std::string &_url) noexcept = 0;
};

static size_t getData(char		  *_p_data,
                      size_t	   _size,
                      size_t	   _nmemb,
                      std::string *_p_str) noexcept {
    _p_str->append(_p_data, _size * _nmemb);
	return _size * _nmemb;
}

#endif 