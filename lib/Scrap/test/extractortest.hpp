#ifndef _TEST_EXTRACTOR_HPP
#define _TEST_EXTRACTOR_HPP

#include "test.hpp"
#include "../include/extractor.hpp"
#include "../include/htmlextractor.hpp"

TEMPLATE()
void extractorTest() {
    std::vector<SPtr>        not_extracted {
        SPtr { new std::string { "httpffseffesfs." } },
        SPtr { new std::string { "http\n\t." } },
        SPtr { new std::string { "http222 \n\n." } },
        SPtr { new std::string { "https." } },
        SPtr { new std::string { "httphttps." } }
    };
    std::vector<std::string> excepted {
        "httpffseffesfs", "http\n\t", 
        "http222 \n\n", "https", "httphttps"
    };
    try {
        std::shared_ptr<IBaseExtractor> p_derived { new Derived { } };
        Extractor                       extractor { p_derived };
        for (size_t i { }; i < not_extracted.size(); ++i) {
            auto temp {
                extractor.extract(not_extracted[i], "http", ".", -1)
            };
            assert(temp[0] == excepted[i]);
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        TEST_FAILED();
    }

    TEST_OK()
}

#endif 