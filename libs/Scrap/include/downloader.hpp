#ifndef DOWNLOADER_HPP
#define DOWNLOADER_HPP

#include <memory>
#include <future>
#include "interface/ibasedownloader.hpp"
#include "scrapexception.hpp"

template
class SCRAP_API std::shared_ptr<IBaseDownloader>;

class SCRAP_API Downloader {
private:
    std::shared_ptr<IBaseDownloader> p_downloader_;

public:
    Downloader(const std::shared_ptr<IBaseDownloader> &_p_derived) noexcept
        : p_downloader_ { _p_derived } { }

    std::string download(const std::string &_url,
                         const std::string &_add_param = "",
                         const std::string &_directory = "");

    void setStrategy(const std::shared_ptr<IBaseDownloader> &_p_derived) noexcept {
        p_downloader_ = _p_derived;
    }
};

#endif 