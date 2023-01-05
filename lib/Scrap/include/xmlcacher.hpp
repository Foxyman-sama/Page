#ifndef XMLCACHER_HPP
#define XMLCACHER_HPP

#include <tinyxml2.h>
#include "interface/ibasecacher.hpp"
#include "dll.hpp"

class SCRAP_API tinyxml2::XMLDocument;

constexpr std::string_view FILENAME { "cache.xml" };

class SCRAP_API XMLCacher 
    : public IBaseCacher {
private:
    tinyxml2::XMLDocument xmldoc_;

private:
    void createFile() noexcept;

public:
   virtual size_t        write(const std::string &_url,
                               StringsVector     &_container) noexcept override;
   virtual StringsVector read(const std::string& _url) noexcept override;
};

#endif 