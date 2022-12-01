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
    struct File {
    private:
        void formatUrl() noexcept;
        void formatName() noexcept;

    public:
        std::string url_;
        std::string name_;

    public:
        void operator=(const std::string &_url) noexcept;
    };

private:
    CURL          *p_curl_;
    std::string    directory_;
    std::ofstream  save_;
    size_t         count_;
    File           current_file_;
    DownloadedMap  map_;

private:   
    std::string initAnswer(const std::string &_url) noexcept;
    std::regex  initRegex(const std::string &_format) noexcept;

    void open() {
        save_.open(directory_ + '/' + current_file_.name_, std::ios_base::binary);
    }
    void close() noexcept {
        save_.close();
    }
    void download(const std::sregex_iterator &_begin,
                  const std::sregex_iterator &_end) noexcept;
    void save() noexcept;
    void output() noexcept;


public:
    explicit PageScraper(const std::string &_url,
                         const std::string &_directory = "",
                         const std::string &_format    = "") noexcept;
    PageScraper() noexcept {
        curl_easy_cleanup(p_curl_);
    }
};

size_t saveString(char        *_p_data,
                  size_t       _size,
                  size_t       _nmemb,
                  std::string *_p_answer) noexcept;
size_t saveFile(char          *_p_data,
                size_t         _size,
                size_t         _nmemb,
                std::ofstream *_p_fout) noexcept;

#endif 