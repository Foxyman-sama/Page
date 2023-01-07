#ifndef IBASECACHER_HPP
#define IBASECACHER_HPP

#include <string>
#include <vector>

using StringsVector = std::vector<std::string>;

class IBaseCacher {
public:
   virtual size_t        write(const std::string &_url,
                               StringsVector     &_container) noexcept = 0;
   virtual StringsVector read(const std::string &_url) noexcept = 0;
};

#endif 