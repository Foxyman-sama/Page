#ifndef CACHER_HPP
#define CACHER_HPP

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "parsedresult.hpp"
#include "stringmanipulator.hpp"

class Cacher {
private:
    std::ofstream cacher_;
    std::ifstream reader_;
    std::string   file_;

public:
    Cacher(const std::string &_folder,
           std::string       &_file) noexcept;

    bool         isCached() noexcept;
    ParsedVector read() noexcept;

    void write(const ParsedVector &_parsed) noexcept;
    void cache(const std::string &_url) noexcept {
        cacher_ << _url;
    }
};

#endif 