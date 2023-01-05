#ifndef _TEST_CACHER_HPP
#define _TEST_CACHER_HPP

#include "test.hpp"
#include "../include/cacher.hpp"
#include "../include/xmlcacher.hpp"

TEMPLATE()
void cacherTest() {
    const std::string        url { "test.com" };
    std::vector<std::string> wait_for_cached {
        "st saed asd sad \n\n\n\n\n",
        "st saasd sad \n\n\n\n\t\t\tgdfgfdgfdgdf\n\n\n\n",
        "s22222fcc",
        " \n",
        "s s sss",
        "He23567\n\n\tfgd\\gbyt"
    };
    try {
        std::shared_ptr<IBaseCacher> p_derived { new Derived { } };
        Cacher                       cacher { p_derived };
        cacher.write(url, wait_for_cached);
        
        auto readed { cacher.read(url) };
        for (size_t i { }; i < wait_for_cached.size(); ++i) {
            assert(readed[i] == wait_for_cached[i]);
        }     
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        TEST_FAILED();
    }

    TEST_OK()
}

#endif 