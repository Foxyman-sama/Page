#ifndef SAVER_HPP
#define SAVER_HPP

#include "ioutput.hpp"

class Saver final : public IOutput {
public:
    virtual bool write(const std::string &_data) noexcept override;

public:
    explicit Saver(const std::string &_name) noexcept { 
        fout_.open(_name, std::ios_base::binary);
    }
    ~Saver() noexcept {
        fout_.close();
    }

    std::ofstream &getSaver() noexcept {
        return fout_;
    }
};

#endif 