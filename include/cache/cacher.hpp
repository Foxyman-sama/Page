#ifndef CACHER_HPP
#define CACHER_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include "parsedresult.hpp"
#include "stringmanipulator.hpp"
#include "cachewriter.hpp"
#include "cachereader.hpp"

class Cacher {
private:
    std::unique_ptr<CacheWriter> cwriter_;
    std::unique_ptr<CacheReader> creader_;

public:
    enum class OpenType {
        ONWRITE,
        ONREAD
    };

public:
    static bool isCached(const std::string &_filename) noexcept;

public:
    Cacher(const std::string &_filename,
           OpenType           _type) noexcept;

    bool isCached() noexcept {
        if (creader_) {
            return creader_->isOpen();
        }

        return false;
    }

    void read(ParsedVector &_parsed) noexcept {
        creader_->read(_parsed);
    }
    void write(const ParsedVector &_parsed) noexcept {
        cwriter_->write(_parsed);
    }
};

#endif 