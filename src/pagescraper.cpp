#include "pagescraper.hpp"

#include <string>

PageScraper::PageScraper(const std::string &_url,
                         const std::string &_format) noexcept {
    std::string answer { };

    p_curl_ = curl_easy_init();
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, &PageScraper::saveAnswer);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &answer);
    curl_easy_perform(p_curl_);
    curl_easy_cleanup(p_curl_);

    std::regex           regex { initRegex(_format) };
    std::sregex_iterator begin {  answer.cbegin(), answer.cend(), regex  };
    std::sregex_iterator end  { };

    download(begin, end, _format);
}

size_t PageScraper::saveAnswer(char        *_data, 
                               size_t       _size,
                               size_t       _nmemb,
                               std::string *_p_answer) noexcept {
    _p_answer->append(_data, _size * _nmemb);

    return _size * _nmemb;
}
size_t PageScraper::saveFile(char          *_data,
                             size_t         _size,
                             size_t         _nmemb,
                             std::ofstream *_p_fout) noexcept {
    _p_fout->write(_data, _size * _nmemb);

    return _size * _nmemb;
}

std::regex PageScraper::initRegex(const std::string &_format) noexcept {
    if (_format.empty()) {
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

        std::cout << url      << '\n';
        std::cout << filename << '\n' << '\n';

        save_.open(filename, std::ios_base::binary);

        p_curl_ = curl_easy_init();
        curl_easy_setopt(p_curl_, CURLOPT_URL, url.c_str());
        curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, &PageScraper::saveFile);
        curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &save_);
        curl_easy_perform(p_curl_);
        curl_easy_cleanup(p_curl_);

        save_.close();
    }
}
void PageScraper::editFilename(std::string &_filename) noexcept {
    _filename.erase(std::remove_if(_filename.begin(), _filename.end(), [&](char _ch) {
        return _ch == '/' ||
        _ch == ':';
    }), _filename.end());
}
