#include "pagescraper.hpp"
#include "test.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    system("mkdir download");
    system("cd download");
    system("cls");

#ifndef RELEASE
    test();
    test2();
#endif 

#ifdef RELEASE
    if (_argc > 2) {
        PageScraper page { _p_argv[1], _p_argv[2] };
    }
    else {
        PageScraper page { _p_argv[1], "" };
    }
#endif

    system("pause");
    system("cls");
}