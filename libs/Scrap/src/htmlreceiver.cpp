#include "htmlreceiver.hpp"

StringPtr HTMLReceiver::receive(const std::string &_url) noexcept {
    std::shared_ptr<std::string> p_answer { new std::string { } };
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(p_curl_, CURLOPT_USERAGENT, USER_AGENT.data());
    curl_easy_setopt(p_curl_, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, HTMLReceiver::getData);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, p_answer.get());

    CURLcode code { curl_easy_perform(p_curl_) };
    if (code != CURLE_OK) {
        return nullptr;
    }

    return p_answer;
}

size_t HTMLReceiver::getData(char        *_p_data,
                             size_t       _size, 
                             size_t       _nmemb,
                             std::string *_p_str) noexcept {
    size_t size { _size * _nmemb };
    _p_str->append(_p_data, size);
    return size;
}
