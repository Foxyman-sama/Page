#ifndef SAVER_HPP
#define SAVER_HPP

#include "ioutput.hpp"

class Saver final : public IOutput {
public:
    virtual bool write(const ParsedVector &_parsed) noexcept override;

public:
    explicit Saver(const std::string &_filename) noexcept { 
        fout_.open(_filename, std::ios_base::binary);
    }
    ~Saver() noexcept {
        fout_.close();
    }

public:
    std::ofstream *operator*() noexcept {
        return &fout_;
    }
};

#endif 