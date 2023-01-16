#ifndef IBASEDOWNLOADER_HPP
#define IBASEDOWNLOADER_HPP

#include <string>
#include "dll.hpp"

class IBaseDownloader {
public:
    virtual std::string download(const std::string &_url,
                                 const std::string &_add_param = "",
                                 const std::string &_directory = "") noexcept = 0;
};

#endif 