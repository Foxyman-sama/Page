#ifndef _TEST_RECEIVER_HPP
#define _TEST_RECEIVER_HPP

#include <iostream>
#include <cassert>
#include "test.hpp"
#include "../include/receiver.hpp"
#include "../include/htmlreceiver.hpp"

TEMPLATE()
void receiverTest() {
    const std::vector<std::string> URLS {
        "https://www.youtube.com/", "https://rozetka.com.ua/ua/",
        "https://en.cppreference.com/w/", "https://leetcode.com/"
    };
    try {
        std::shared_ptr<IBaseReceiver> p_derived { new Derived { } };
        Receiver                       receiver { p_derived };
        for (size_t i { }; i < URLS.size(); ++i) {
            receiver.receive(URLS[i]);
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        TEST_FAILED();
    }

    TEST_OK()
}

#endif 