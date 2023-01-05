#ifndef _TEST_FILTERER_HPP
#define _TEST_FILTERER_HPP

#include "test.hpp"
#include "../include/filterer.hpp"
#include "../include/xmlfilterer.hpp"
#include "../include/vectorfilterer.hpp"

TEMPLATE()
void filtererTest() {
    try {
        std::vector<std::string>       excepted { 
            "st saed asd sad \n\n\n\n\n",
            "st saasd sad \n\n\n\n\t\t\tgdfgfdgfdgdf\n\n\n\n",
            " \n",
            "He23567\n\n\tfgd\\gbyt"
        };
        std::vector<std::string>       filtered { };
        std::shared_ptr<IBaseFilterer> p_derived { new Derived { } };
        Filterer                       filterer { p_derived };

        if (typeid(Derived) == typeid(XMLFilterer)) {
            filtered = filterer.filter("test.com", "\n");
        }
        else {
            std::vector<std::string> wait_for_filtered {
                "st saed asd sad \n\n\n\n\n",
                "st saasd sad \n\n\n\n\t\t\tgdfgfdgfdgdf\n\n\n\n",
                "s22222fcc",
                " \n",
                "s s sss",
                "He23567\n\n\tfgd\\gbyt"
            };
            filtered = filterer.filter(&wait_for_filtered, "\n");
        }

        for (size_t i { }; i < excepted.size(); ++i) {
            assert(excepted[i] == filtered[i]);
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        TEST_FAILED();
    }

    TEST_OK()
}


#endif 