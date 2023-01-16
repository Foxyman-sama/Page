#ifndef HTMLRECEIVER_HPP
#define HTMLRECEIVER_HPP

#include <curl/curl.h>
#include "interface/ibasereceiver.hpp"

class SCRAP_API HTMLReceiver final
	: public IBaseReceiver {
private:
	CURL *p_curl_;

public:
	virtual StringPtr receive(const std::string &_url) noexcept override;

private:
	static size_t getData(char		  *_p_data,
						  size_t	   _size,
						  size_t	   _nmemb,
						  std::string *_p_str) noexcept;

public:
	HTMLReceiver() noexcept {
		p_curl_ = curl_easy_init();
	}
	~HTMLReceiver() noexcept {
		curl_easy_cleanup(p_curl_);
	}
};


#endif 