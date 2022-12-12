#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <curl/curl.h>
#include "saver.hpp"
#include "parsedresult.hpp"

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