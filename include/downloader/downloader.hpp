#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <curl/curl.h>
#include "saver.hpp"
#include "parsedresult.hpp"

constexpr std::string_view USER_AGENT {
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
    "AppleWebKit/537.36 (KHTML, like Gecko) "
    "Chrome/108.0.0.0 Safari/537.36"
};

class Downloader {
private:
    CURL  *p_curl_;

private:
    static size_t getFile(char          *_p_data,
                          size_t         _size,
                          size_t         _nmemb,
                          std::ofstream *_p_save) noexcept;

public:
    Downloader() noexcept {
        p_curl_ = curl_easy_init();
    }
    ~Downloader() noexcept {
        curl_easy_cleanup(p_curl_);
    }

    bool download(const ParsedResult &_parsed) noexcept;
};

#endif 