#ifndef IOUTPUT_HPP
#define IOUTPUT_HPP

#include <fstream>

class IOutput {
protected:
    std::ofstream fout_;

public:
    virtual bool write(const std::string &_data) noexcept = 0;

public:
    virtual ~IOutput() noexcept { };
};

#endif 