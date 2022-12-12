#ifndef CHECKER_HPP
#define CHECKER_HPP

#include "parsedresult.hpp"
#include "iinput.hpp"

class Checker final : public IInput {
private:
    std::string folder_;

public:
    virtual bool read(ParsedVector &_parsed) noexcept override;

public:
    Checker(const std::string &_folder) noexcept :
        folder_ { _folder } { }
};

#endif 