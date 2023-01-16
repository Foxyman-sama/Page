#include "mediadownloader.hpp"

std::string MediaDownloader::download(const std::string &_url,
                                      const std::string &_add_param,
                                      const std::string &_directory) noexcept {
    auto          format_name { [&] () {
        std::string result { _url };
        for (size_t i { }; i < result.size(); ++i) {
            char symbol { result[i] };
            if ((!isalnum(symbol)) && (symbol != '.')) {
                result[i] = '#';
            }
        }

        return result;
    } };
    std::string   formated_name { format_name() };
    std::ofstream fout { 
        _directory + formated_name + _add_param, std::ios_base::binary 
    };
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(p_curl_, CURLOPT_USERAGENT, USER_AGENT.data());
    curl_easy_setopt(p_curl_, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, MediaDownloader::downloadData);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &fout);

    CURLcode code { curl_easy_perform(p_curl_) };
    if (code != CURLE_OK) {
        return "";
    }

    return formated_name;
}

size_t MediaDownloader::downloadData(char          *_p_data,
                                     size_t         _size,
                                     size_t         _nmemb, 
                                     std::ofstream *_p_fout) noexcept {
    size_t size { _size * _nmemb };
    _p_fout->write(_p_data, size);
    return size; 
}
