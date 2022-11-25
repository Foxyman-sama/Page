#ifndef PAGESCRAPER_HPP
#define PAGESCRAPER_HPP

#include <iostream>
#include <fstream>
#include <regex>
#include <curl/curl.h>

class PageScraper {
private:
    CURL          *p_curl_;
    std::ofstream  save_;

private:   
    size_t saveFile(char          *_data,
                    size_t         _size,
                    size_t         _nmemb,
                    std::ofstream *_p_fout) noexcept;

    void download(std::sregex_iterator  _begin,
                  std::sregex_iterator  _end,
                  const std::string    &_format) noexcept;


public:
    explicit PageScraper(const std::string &_url,
                         const std::string &_format) noexcept;
};

#endif 