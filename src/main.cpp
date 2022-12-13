#define TESTMODE1

#ifndef TESTMODE

#include "userfunctions.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, "");   
    
    user::start(_argc, _p_argv);

    system("pause");
}

#endif

#ifdef TESTMODE

#include "test.hpp"

int main() {
    setlocale(0, ".UTF8");

    testConfiguration();
    test1();
    test2();
    test3();
    test4();
    test5();

    system("pause");
}

#endif

