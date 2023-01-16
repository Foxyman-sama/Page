#include "vectorfilterer.hpp"

std::vector<std::string> VectorFilterer::filter(const std::any                 &_any,
                                                const std::vector<std::string> &_filters) noexcept {
    if (_any.type() != typeid(std::vector<std::string> *)) {
        return std::vector<std::string> { };
    }

    auto                      p_vec { std::any_cast<std::vector<std::string> *>(_any) };
    std::vector<std::string>  filtered { };
    for (size_t i { }; i < p_vec->size(); ++i) {
        std::string temp { p_vec->operator[](i) };
        for (size_t i { }; i < _filters.size(); ++i) {
            if (temp.find(_filters[i]) != std::string::npos) {
                filtered.emplace_back(temp);
                break;
            }
        }
    }

    std::sort(filtered.begin(), filtered.end());
    
    auto pos { std::unique(filtered.begin(), filtered.end()) };
    filtered.erase(pos, filtered.end()); 
    return filtered;
}
