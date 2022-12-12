#ifndef IOUTPUT_HPP
#define IOUTPUT_HPP

#include <fstream>
#include "parsedresult.hpp"

class IOutput {
protected:
    std::ofstream fout_;

public:
    virtual bool write(const ParsedVector &_parsed) noexcept = 0;

public:
    virtual ~IOutput() noexcept = default;

    bool isOpen() const noexcept {
        return fout_.is_open();
    }
};

#endif 