#ifndef CACHER_HPP
#define CACHER_HPP

#include <memory>
#include "interface/ibasecacher.hpp"
#include "scrapexception.hpp"
#include "dll.hpp"

template
class SCRAP_API std::shared_ptr<IBaseCacher>;

// @brief Class used for caching information
class SCRAP_API Cacher {
private:
    std::shared_ptr<IBaseCacher> p_cacher_;

public:
    Cacher(const std::shared_ptr<IBaseCacher> &_p_derived) noexcept
        : p_cacher_ { _p_derived } { }

    // @brief Used to store data in the cache
    // @param _url       - cached data header
    // @param _container - where do we store
    // @return Amount of cached information
    size_t        write(const std::string &_url,
                        StringsVector     &_container);
    // @brief Used to read data out the cache
    // @param _url       - cached data header
    // @return Read cached data
    StringsVector read(const std::string &_url);
};

#endif 