#ifndef _TEST_FORMATER_HPP
#define _TEST_FORMATER_HPP

#include "test.hpp"
#include "../include/formater.hpp"
#include "../include/htmlformater.hpp"

TEMPLATE()
void formaterTest() {
    std::vector<SPtr>        not_formated {
        SPtr { new std::string { "st saed asd sad \n\n\n\n\n" } },
        SPtr { new std::string { "st saasd sad \n\n\n\n\t\t\tgdfgfdgfdgdf\n\n\n\n" } },
        SPtr { new std::string { "s22222fcc" } },
        SPtr { new std::string { " \n" } },
        SPtr { new std::string { "s s sss" } },
        SPtr { new std::string { "He23567\n\n\tfgd\\gbyt" } },
    };
    std::vector<std::string> excepted {
        "stsaedasdsad", "stsaasdsadgdfgfdgfdgdf",
        "s22222fcc", "", "sssss", "He23567fgd\\gbyt" 

    };
    try {
        std::shared_ptr<IBaseFormater> p_derived { new Derived { } };
        Formater                       formater { p_derived };
        for (size_t i { }; i < not_formated.size(); ++i) {
            formater.format(not_formated[i]);
            assert(*not_formated[i] == excepted[i]);
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        TEST_FAILED();
    }

    TEST_OK()
}

#endif 