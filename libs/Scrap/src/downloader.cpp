#include "downloader.hpp"

std::string Downloader::download(const std::string &_url, 
                                 const std::string &_add_param, 
                                 const std::string &_directory) {
    auto downloaded { p_downloader_->download(_url, _add_param, _directory) };
    if (downloaded.empty()) {
        excp(Cause::BADDOWNLOAD);
    }

    return downloaded;
}
