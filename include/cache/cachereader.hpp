#ifndef CACHEREADER_HPP
#define CACHEREADER_HPP

#include "iinput.hpp"

class CacheReader final : public IInput{
private:
    std::string filename_;

public:
    virtual bool read(ParsedVector &_parsed) noexcept override;

public:
    CacheReader(const std::string &_filename) noexcept :
        filename_ { _filename } { 
        fin_.open(_filename);
    }
    ~CacheReader() noexcept {
        fin_.close();
    }
};

#endif 