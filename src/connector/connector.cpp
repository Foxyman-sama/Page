#include "connector.hpp"

size_t Connector::getHtml(char        *_p_data, 
                          size_t       _size, 
                          size_t       _nmemb, 
                          std::string *_p_answer) noexcept {
    _p_answer->append(_p_data, _size * _nmemb);

    return _size * _nmemb;
}

bool Connector::connect(const std::string &_url) noexcept {
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, Connector::getHtml);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &answer_);
    curl_easy_setopt(p_curl_, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                                                        "AppleWebKit/537.36 (KHTML, like Gecko) "
                                                        "Chrome/108.0.0.0 Safari/537.36");

    if (curl_easy_perform(p_curl_) != CURLE_OK) {
        return false;
    }

    return true;
}
