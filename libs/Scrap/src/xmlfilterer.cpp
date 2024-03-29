#include "xmlfilterer.hpp"

std::vector<std::string> XMLFilterer::filter(const std::any                 &_any, 
                                             const std::vector<std::string> &_filters) noexcept {
    if (_any.type() != typeid(const char *)) {
        return std::vector<std::string> { };
    }
    if (xmldoc_.LoadFile("cache.xml") != 0) {
        return std::vector<std::string> { };
    }

    std::string           url { std::any_cast<const char *>(_any) };
    tinyxml2::XMLElement *p_root { xmldoc_.FirstChildElement() };
    tinyxml2::XMLElement *p_site { p_root->FirstChildElement() };
    while (p_site) {
        if (url == p_site->FirstAttribute()->Value()) {
            break;
        }

        p_site = p_site->NextSiblingElement();
    }

    if (!p_site) {
        return std::vector<std::string> { }; 
    }

    std::vector<std::string>  filtered { };
    tinyxml2::XMLElement     *p_cached { p_site->FirstChildElement() };
    while (p_cached) {
        std::string temp { p_cached->FirstAttribute()->Value() };
        for (size_t i { }; i < _filters.size(); ++i) {
            if (temp.find(_filters[i]) != std::string::npos) {
                filtered.emplace_back(temp);
                break;
            }
        }

        p_cached = p_cached->NextSiblingElement();
    }

    std::sort(filtered.begin(), filtered.end());

    auto pos { std::unique(filtered.begin(), filtered.end()) };
    filtered.erase(pos, filtered.end()); 
    return filtered;
}
