#ifndef FORMATER_HPP
#define FORMATER_HPP

#include "interface/ibaseformater.hpp"
#include "scrapexception.hpp"
#include "dll.hpp"

template
class SCRAP_API std::shared_ptr<IBaseFormater>;

// Class used to format information
class SCRAP_API Formater {
private:
    std::shared_ptr<IBaseFormater> p_formater_;

public:
    Formater(const std::shared_ptr<IBaseFormater> &_p_derived) noexcept 
        : p_formater_ { _p_derived } { }

    // @brief Used to format information
    // @param _p_str - pointer to string
    // @return Number of formatting operations
    size_t format(StringPtr &_p_str);
};

#endif 