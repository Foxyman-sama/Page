#ifndef _TEST_HPP
#define _TEST_HPP

#include <iostream>
#include <vector>
#include <cassert>

using SPtr = std::shared_ptr<std::string>;

#define TEST_OK()     std::cerr << "Test: " << __func__ << "\tOK!\n\n";
#define TEST_FAILED() std::cerr << "Test: " << __func__ << "\tfailed!\n\n"; return;           
#define TEMPLATE()    template <typename Derived>     

#endif 