#ifndef IINPUT_HPP
#define IINPUT_HPP

#include <fstream>
#include "parsedresult.hpp"

class IInput {
protected:
    std::ifstream fin_;

public:
    virtual bool read(ParsedVector &_parsed) noexcept = 0;

public:
    virtual ~IInput() noexcept = default;

    bool isOpen() const noexcept {
        return fin_.is_open();
    }
};

#endif 