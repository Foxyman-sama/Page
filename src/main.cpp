#include "pagescraper.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    if (_argc > 2) {
        PageScraper page { _p_argv[1], _p_argv[2] };
    }
    else {
        PageScraper page { _p_argv[1], "" };
    }

    system("pause");
}