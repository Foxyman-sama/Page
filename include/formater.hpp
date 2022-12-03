#ifndef FORMATER_HPP
#define FORMATER_HPP

#include "parsedresult.hpp"

class Formater {
private:
    ParsedVector parsed_;

private:
    void format() noexcept;

public:
    explicit Formater(const ParsedVector &_parsed) noexcept :
        parsed_ { _parsed } { 
        format();
    }

    auto &getFormated() const noexcept {
        return parsed_;
    }
};

#endif 