#ifndef CACHEREADER_HPP
#define CACHEREADER_HPP

#include <string>
#include <vector>
#include "iinput.hpp"

class CacheReader final : public IInput{
private:
    std::string filename_;

public:
    virtual bool read(std::vector<std::string> &_vector) noexcept override;

public:
    CacheReader(const std::string &_filename) noexcept :
        filename_ { _filename } { 
        fin_.open(_filename);
    }
    ~CacheReader() noexcept {
        fin_.close();
    }

    bool isOpen() const noexcept {
        return fin_.is_open();
    }
};

#endif 