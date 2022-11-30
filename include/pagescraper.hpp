#ifndef PAGESCRAPER_HPP
#define PAGESCRAPER_HPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>
#include <thread>
#include <curl/curl.h>

class PageScraper {
private:
    using DownloadedMap = std::unordered_map<std::string, bool>;

private:
    CURL          *p_curl_;
    std::ofstream  save_;
    size_t         count_;
    DownloadedMap  map_;

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
    std::string createFilename(const std::string &_url) noexcept;

    void download(std::sregex_iterator  &_begin,
                  std::sregex_iterator  &_end,
                  const std::string     &_format) noexcept;
    void save(const std::string &_url,
              const std::string &_filename) noexcept;
    void output(const std::string &_url,
                const std::string &_filename) noexcept;
    void open(const std::string &_filename) noexcept;
    void close() noexcept {
        save_.close();
    }

public:
    explicit PageScraper(const std::string &_url,
                         const std::string &_format = "") noexcept;
    PageScraper() noexcept {
        curl_easy_cleanup(p_curl_);
    }
};

#endif 