#include "pagescraper.hpp"

PageScraper::PageScraper(const std::string &_url,
                         const std::string &_format) noexcept {
    std::regex  regex { "src=\"(.+?[" + _format + "]?)\"" };
    std::string answer { };
    auto        begin { std::sregex_iterator { answer.cbegin(), answer.cend(), regex } };
    auto        end { std::sregex_iterator { } };

    download(begin, end, _format);
}

size_t PageScraper::saveFile(char          *_data,
                             size_t         _size,
                             size_t         _nmemb,
                             std::ofstream *_p_fout) noexcept {
    _p_fout->write(_data, _size * _nmemb);

    return _size * _nmemb;
}


void PageScraper::download(std::sregex_iterator  _begin, 
                           std::sregex_iterator  _end,
                           const std::string    &_format) noexcept {
    size_t counter { };

    for (auto i { _begin }; i != _end; ++i) {
        std::string url { "https:" + i->operator[](1).str(), std::ios_base::binary };

        save_.open(std::to_string(++counter) + '.' + _format );

        p_curl_ = curl_easy_init();
        curl_easy_setopt(p_curl_, CURLOPT_URL, url);
        curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, &PageScraper::saveFile);
        curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &save_);
        curl_easy_perform(p_curl_);
        curl_easy_cleanup(p_curl_);

        save_.close();
    }
}
