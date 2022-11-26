#include "pagescraper.hpp"

#include <string>

PageScraper::PageScraper(const std::string &_url,
                         const std::string &_format) noexcept {
    std::string          answer { initAnswer(_url) };
    std::regex           regex { initRegex(_format) };
    std::sregex_iterator begin {  answer.cbegin(), answer.cend(), regex  };
    std::sregex_iterator end  { };

    download(begin, end, _format);
}

size_t PageScraper::saveAnswer(char        *_p_data, 
                               size_t       _size,
                               size_t       _nmemb,
                               std::string *_p_answer) noexcept {
    _p_answer->append(_p_data, _size * _nmemb);

    return _size * _nmemb;
}
size_t PageScraper::saveFile(char          *_p_data,
                             size_t         _size,
                             size_t         _nmemb,
                             std::ofstream *_p_fout) noexcept {
    _p_fout->write(_p_data, _size * _nmemb);

    return _size * _nmemb;
}

std::string PageScraper::initAnswer(const std::string &_url) noexcept{
    std::string answer { };

    p_curl_ = curl_easy_init();
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, &PageScraper::saveAnswer);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &answer);
    curl_easy_perform(p_curl_);
    curl_easy_cleanup(p_curl_);

    return answer;
}
std::regex  PageScraper::initRegex(const std::string &_format) noexcept {
    if (!_format.empty()) {
        return std::regex { "<img.*?src=\"(.+?" + _format + ")\"" };
    }
    else {
        return std::regex { "<img.*?src=\"(.+?)\"" };
    }
}

void PageScraper::download(std::sregex_iterator  _begin, 
                           std::sregex_iterator  _end,
                           const std::string    &_format) noexcept {
    for (auto i { _begin }; i != _end; ++i) {
        std::string url { i->operator[](1).str() };
        std::string filename { url };

        checkUrl(url);
        editFilename(filename);
        input(url, filename);
        save(url, filename);
    }
}
void PageScraper::save(const std::string &_url,
                       const std::string &_filename) noexcept {
    save_.open("download/" + _filename, std::ios_base::binary);

    p_curl_ = curl_easy_init();
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, &PageScraper::saveFile);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &save_);
    curl_easy_perform(p_curl_);
    curl_easy_cleanup(p_curl_);

    save_.close();
}
void PageScraper::editFilename(std::string &_filename) noexcept {
    _filename.erase(std::remove_if(_filename.begin(), _filename.end(), [&](char _ch) {
        return _ch == '/' ||
        _ch == ':';
    }), _filename.end());
}
void PageScraper::input(const std::string &_url,
                        const std::string &_filename) noexcept {
    std::cout.width(10);
    std::cout << "URL: "      << _url << '\n';
    std::cout.width(10);
    std::cout << "FILENAME: " << _filename << '\n' << '\n';
}
