#include "downloader.hpp"

size_t Downloader::getFile(char			 *_p_data, 
						   size_t		  _size,
						   size_t		  _nmemb, 
						   std::ofstream *_p_save) noexcept {
	_p_save->write(_p_data, _size * _nmemb);

	return _size * _nmemb;
}

bool Downloader::download(const ParsedResult &_parsed) noexcept {
    Saver saver { _parsed.format_ } ;

    curl_easy_setopt(p_curl_, CURLOPT_URL, _parsed.url_.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, Downloader::getFile);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &saver.getSave());

    if (curl_easy_perform(p_curl_) != CURLE_OK) {
        return false;
    }

    return true;
}
