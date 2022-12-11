#ifndef USERFUNCTIONS_HPP
#define USERFUNCTIONS_HPP

#ifndef NDEBUG
#include <cassert>
#endif

#include "connector.hpp"
#include "parser.hpp"
#include "formater.hpp"
#include "downloader.hpp"
#include "output.hpp"
#include "checker.hpp"
#include "indexer.hpp"
#include "cacher.hpp"
#include "prep.hpp"

namespace user {
    constexpr size_t MAX_TRY_COUNT { 10 };

    std::string  connect(const std::string &_url);
    ParsedVector parse(const std::string &_answer,
                       const std::string &_formats);
    bool tryDownload(Downloader         &_downloader,
                     const ParsedResult &_parsed);

    void prepare(std::string &_answer) noexcept;
    void format(ParsedVector &_parsed) noexcept;
    void download(ParsedVector &_parsed) noexcept;
}

#endif 