#include "cacher.hpp"

size_t        Cacher::write(const std::string &_url, 
                            StringsVector     &_container) {
    size_t writed { p_cacher_->write(_url, _container) };
    if (writed == 0) {
        excp(Cause::BADCACHEWRITE);
    }

    return writed;
}
StringsVector Cacher::read(const std::string &_url) {
    StringsVector strs { p_cacher_->read(_url) };
    if (strs.empty()) {
        excp(Cause::BADCACHEREAD);
    }

    return strs;
}
