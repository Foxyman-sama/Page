#include "pagescraper.hpp"

PageScraper::PageScraper(const std::string &_url,
                         const std::string &_directory, 
                         const std::string &_format) noexcept :
    directory_ { _directory },
    count_ { } {
    std::regex  folder { "\/\/([^\/]+)" };
    std::cmatch result { };

    std::regex_search(_url.c_str(), result, folder);

    if (!result.size()) {
        std::cerr << "Bad URL. Try again." << '\n';
    }
    else {
        directory_ = directory_ + '/' + result[1].str();

        system(std::string { "mkdir \"" + directory_ + "\"" }.c_str());

        std::string          answer { initAnswer(_url) };
        std::regex           regex { initRegex(_format) };
        std::sregex_iterator begin { answer.cbegin(), answer.cend(), regex };
        std::sregex_iterator end { };

        download(begin, end);
    }
}

std::string PageScraper::initAnswer(const std::string &_url) noexcept{
    std::string answer { };

    p_curl_ = curl_easy_init();
    curl_easy_setopt(p_curl_, CURLOPT_URL, _url.c_str());
    curl_easy_setopt(p_curl_, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, saveString);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &answer);
    curl_easy_perform(p_curl_);

    return answer;
}
std::regex  PageScraper::initRegex(const std::string &_format) noexcept {
    if (!_format.empty()) {
        return std::regex { "(https|http)[^\"|^'|^;]+(" + _format + ")[^!-/^?]?" };
    }
    else {
        return std::regex { "(https|http)[^\"|^'|^;]+(rj|jpg|png)[^!-/^?]?" };
    }
}

void PageScraper::download(const std::sregex_iterator &_begin, 
                           const std::sregex_iterator &_end) noexcept {
    for (auto i { _begin }; i != _end; ++i, ++count_);

    curl_easy_setopt(p_curl_, CURLOPT_WRITEFUNCTION, saveFile);
    curl_easy_setopt(p_curl_, CURLOPT_WRITEDATA, &save_);

    for (auto i { _begin }; i != _end; ++i) {
        system("cls");

        current_file_ = i->str();

        save();
        output();
    }
}
void PageScraper::save() noexcept {
    if (map_[current_file_.name_]) {
        return;
    }

    map_[current_file_.name_] = true;

    open();

    curl_easy_setopt(p_curl_, CURLOPT_URL, current_file_.url_.c_str());
    curl_easy_perform(p_curl_);

    close();
}
void PageScraper::output() noexcept {
    std::cout.width(10);
    std::cout << "URL: "      << current_file_.url_ << '\n';

    std::cout.width(10);
    std::cout << "FILENAME: " << current_file_.name_ << '\n' << '\n';

    std::cout.width(10);
    std::cout << "Left: " << --count_ << '\n' << '\n';

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void PageScraper::File::formatUrl() noexcept { 
    size_t pos { url_.find("\\") };

    while (pos != std::string::npos) {
        url_.erase(url_.begin() + pos);

        pos = url_.find("\\");
    }

    pos = url_.find("u002F");

    while (pos != std::string::npos) {
        url_.replace(url_.begin() + pos, url_.begin() + pos + 5, "/");

        pos = url_.find("u002F");
    }
}
void PageScraper::File::formatName() noexcept {
    name_.erase(std::remove_if(name_.begin(), name_.end(),
                [&](char _ch) {
        return _ch == '/'  ||
               _ch == '\\' ||
               _ch == ':';
    }), name_.end());

    if (name_.find("rj")) {
        name_ = name_ + ".png";
    }
}

void PageScraper::File::operator=(const std::string &_url) noexcept {
    url_  = _url;
    formatUrl();

    name_ = _url;
    formatName();
}

size_t saveString(char        *_p_data,
                  size_t       _size,
                  size_t       _nmemb,
                  std::string *_p_str) noexcept {
    _p_str->append(_p_data, _size * _nmemb);

    return _size * _nmemb;
}
size_t saveFile(char          *_p_data,
                size_t         _size,
                size_t         _nmemb,
                std::ofstream *_p_fout) noexcept {
    _p_fout->write(_p_data, _size * _nmemb);

    return _size * _nmemb;
}
