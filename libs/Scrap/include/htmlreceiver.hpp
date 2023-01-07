#ifndef HTMLRECEIVER_HPP
#define HTMLRECEIVER_HPP

#include <curl/curl.h>
#include "interface/ibasereceiver.hpp"
#include "dll.hpp"

class SCRAP_API HTMLReceiver final
	: public IBaseReceiver {
private:
	CURL *p_curl_;

public:
	virtual StringPtr sendRequest(const std::string &_url) noexcept override;

public:
	HTMLReceiver() noexcept {
		p_curl_ = curl_easy_init();
	}
	~HTMLReceiver() noexcept {
		curl_easy_cleanup(p_curl_);
	}
};

#endif 