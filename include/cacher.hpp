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
    Cacher(const std::string &_filename,
           OpenType           _type) noexcept;

    bool isCached() noexcept {
        if (creader_) {
            return creader_->isOpen();
        }

        return false;
    }
    
    void read(ParsedVector &_parsed) noexcept;
    void write(ParsedVector &_parsed) noexcept;
};

#endif 