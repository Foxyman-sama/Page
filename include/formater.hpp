#ifndef FORMATER_HPP
#define FORMATER_HPP

#include "parsedresult.hpp"

class Formater {
private:
    ParsedVector parsed_;

private:
    std::string createName(const std::string &_name) noexcept;

    void format() noexcept;
    void replace(std::string       &_string,
                 const std::string  _current,
                 const std::string  _new) noexcept;

public:
    explicit Formater(const ParsedVector &_parsed) noexcept :
        parsed_ { _parsed } { 
        format();
    }

    ParsedVector &getFormated() noexcept {
        return parsed_;
    }
};

#endif 