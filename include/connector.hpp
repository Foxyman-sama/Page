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
    const auto &getAnswer() const noexcept {
        return answer_;
    }
    bool        connect(const std::string &_url) noexcept;
};

#endif 