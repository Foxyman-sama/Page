#ifndef IINPUT_HPP
#define IINPUT_HPP

#include <fstream>

class IInput {
protected:
    std::ifstream fin_;

public:
    virtual bool read(std::vector<std::string> &_vector) noexcept = 0;

public:
    virtual ~IInput() noexcept { };
};

#endif 