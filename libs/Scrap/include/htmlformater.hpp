#ifndef HTMLFORMATER_HPP
#define HTMLFORMATER_HPP

#include <array>
#include "interface/ibaseformater.hpp"
#include "dll.hpp"

constexpr size_t                                      ENTITYS_COUNT { 7 };
constexpr std::array<std::string_view, ENTITYS_COUNT> ENTITYS {
    "&amp;", "&lt;", "&gt;", "&quot;", "\\u0026", "\\/", "\\u003d"
};
constexpr std::array<std::string_view, ENTITYS_COUNT> REPLACEMENTS {
    "&", "<", ">", "\"", "&", "/", "="
};

class SCRAP_API HTMLFormater final
    : public IBaseFormater {
public:
    virtual size_t format(StringPtr &_p_str) noexcept override;
};

#endif 