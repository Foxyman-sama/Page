#include "vectorfilterer.hpp"

std::vector<std::string> VectorFilterer::filter(const std::any    &_any,
                                                const std::string &_filter) noexcept {
    if (_any.type() != typeid(std::vector<std::string> *)) {
        return std::vector<std::string> { };
    }

    auto                      p_vec { std::any_cast<std::vector<std::string> *>(_any) };
    std::vector<std::string>  filtered { };
    for (size_t i { }; i < p_vec->size(); ++i) {
        std::string temp { p_vec->operator[](i) };
        if (temp.find(_filter) != std::string::npos) {
            filtered.emplace_back(temp);
        }
    }

    return filtered;
}
