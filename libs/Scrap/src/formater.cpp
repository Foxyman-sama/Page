#include "formater.hpp"

size_t Formater::format(StringPtr &_p_str) {
    size_t count { p_formater_->format(_p_str) };
    if (!count) {
        excp(Cause::BADFORMAT);
    }

    return count;
}
