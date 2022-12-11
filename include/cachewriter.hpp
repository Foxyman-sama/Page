#ifndef CACHEWRITER_HPP
#define CACHEWRITER_HPP

#include "ioutput.hpp"

class CacheWriter final : public IOutput {
private:
    std::string filename_;

public:
    virtual bool write(const std::string &_data) noexcept override;

public:
    CacheWriter(const std::string &_filename) noexcept :
        filename_ { _filename } {
        fout_.open(_filename, std::ios_base::binary);
    }
    ~CacheWriter() noexcept {
        fout_.close();
    }
};

#endif 