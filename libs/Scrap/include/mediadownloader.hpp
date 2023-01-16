#ifndef MEDIADOWNLOADER_HPP
#define MEDIADOWNLOADER_HPP

#include <curl/curl.h>
#include <fstream>
#include "interface/ibasedownloader.hpp"

class SCRAP_API MediaDownloader final 
    : public IBaseDownloader {
private:
    CURL *p_curl_;

public:
    virtual std::string download(const std::string &_url,
                                 const std::string &_add_param = "",
                                 const std::string &_directory = "") noexcept override;

private:
    static size_t downloadData(char		     *_p_data,
                               size_t	      _size,
                               size_t	      _nmemb,
                               std::ofstream *_p_fout) noexcept;

public:
    MediaDownloader() noexcept {
        p_curl_ = curl_easy_init();
    }
    ~MediaDownloader() noexcept {
        curl_easy_cleanup(p_curl_);
    }
};

#endif 