#define TESTMODE

#ifndef TESTMODE

#include "userfunctions.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, "");   
    
    scrap::start();

    system("pause");
}

#endif

#ifdef TESTMODE

#include "test.hpp"

int main() {
    setlocale(0, ".UTF8");

    test();

    system("pause");
}

#endif

