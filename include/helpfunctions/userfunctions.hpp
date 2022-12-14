#ifndef USERFUNCTIONS_HPP
#define USERFUNCTIONS_HPP

#ifndef NDEBUG
#include <cassert>
#endif

#include "headers.hpp"

namespace scrap {
    constexpr std::string_view FORMATS { ".png|.jpg|-rj|-mo|.ico" };
    constexpr size_t           MAX_TRY_COUNT { 10 };

    std::string  connect(const std::string &_url);
    ParsedVector parse(const std::string &_answer,
                       const std::string &_formats = FORMATS.data());
    bool tryDownload(Downloader         &_downloader,
                     const ParsedResult &_parsed);

    void start() noexcept;
    void scraping(std::string       &_url) noexcept;
    void prepare(std::string &_answer) noexcept;
    void format(ParsedVector &_parsed) noexcept;
    void download(ParsedVector &_parsed) noexcept;
}

#endif 