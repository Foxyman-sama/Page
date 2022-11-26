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
    static size_t saveAnswer(char        *_p_data,
                             size_t       _size,
                             size_t       _nmemb,
                             std::string *_p_answer) noexcept;
    static size_t saveFile(char          *_p_data,
                           size_t         _size,
                           size_t         _nmemb,
                           std::ofstream *_p_fout) noexcept;

private:   
    std::string initAnswer(const std::string &_url) noexcept;
    std::regex  initRegex(const std::string &_format) noexcept;

    void checkUrl(std::string &_url) noexcept {
        if (_url.find("https:") == std::string::npos) {
            _url = "https:" + _url;
        }
    }
    void download(std::sregex_iterator  _begin,
                  std::sregex_iterator  _end,
                  const std::string    &_format) noexcept;
    void save(const std::string &_url,
              const std::string &_filename) noexcept;
    void editFilename(std::string &_filename) noexcept;
    void input(const std::string &_url,
               const std::string &_filename) noexcept;

public:
    explicit PageScraper(const std::string &_url,
                         const std::string &_format) noexcept;
};

#endif 