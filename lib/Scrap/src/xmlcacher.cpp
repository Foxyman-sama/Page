#include "xmlcacher.hpp"

void XMLCacher::createFile() noexcept { 
    auto *p_root { xmldoc_.NewElement("root") };
    xmldoc_.InsertFirstChild(p_root);
    xmldoc_.SaveFile(FILENAME.data());
}

size_t        XMLCacher::write(const std::string &_url,
                               StringsVector     &_container) noexcept {
    if (xmldoc_.LoadFile("cache.xml") != 0) {
        createFile();
        return write(_url, _container);
    }

    auto                 *p_root { xmldoc_.FirstChildElement() };
    tinyxml2::XMLElement *p_site { };
    if (p_root->FirstChildElement()) {
        p_site = p_root->FirstChildElement();
        while (p_site) {
            if (p_site->FirstAttribute()->Value() == _url) {
                p_root->DeleteChild(p_site);
                break;
            }

            p_site = p_site->NextSiblingElement();
        }
    }

    size_t counter { };
    p_site = p_root->InsertNewChildElement("site");
    p_site->SetAttribute("url", _url.c_str());
    for (size_t i { }; i < _container.size(); ++i) {
        auto *p_cached { p_site->InsertNewChildElement("cached") };
        p_cached->SetAttribute("data", _container[i].c_str());
        ++counter;
    }

    xmldoc_.SaveFile(FILENAME.data());
    return counter;
}
StringsVector XMLCacher::read(const std::string &_url) noexcept {
    if (xmldoc_.LoadFile(FILENAME.data()) != 0) {
        return StringsVector { };
    }

    StringsVector  strs { };
    auto          *p_root { xmldoc_.FirstChildElement() };
    auto          *p_site { p_root->FirstChildElement() };
    while (p_site) {
        if (p_site->FirstAttribute()->Value() == _url) {
            break;
        }

        p_site = p_site->NextSiblingElement();
    }

    if (!p_site) {
        return StringsVector { };
    }

    auto *p_cached { p_site->FirstChildElement() };
    while (p_cached) {
        strs.emplace_back(p_cached->FirstAttribute()->Value());
        p_cached = p_cached->NextSiblingElement();
    }

    xmldoc_.SaveFile(FILENAME.data());
    return strs;
}
