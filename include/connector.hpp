#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <iostream>
#include <curl/curl.h>

class Connector {
private:
    CURL        *p_curl_;
    std::string  answer_;

private:
    static size_t getHtml(char        *_p_data,
                          size_t       _size,
                          size_t       _nmemb,
                          std::string *_p_answer) noexcept;

public:   
    Connector() noexcept {
        p_curl_ = curl_easy_init();
    }
    ~Connector() noexcept {
        curl_easy_cleanup(p_curl_);
    }

    const auto &getAnswer() const noexcept {
        return answer_;
    }
    bool        connect(const std::string &_url) noexcept;
};

#endif 