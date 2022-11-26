#include "pagescraper.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    system("mkdir download");
    system("cd download");
    system("cls");

    PageScraper page { "https://hard.rozetka.com.ua/ua/kingston_sa400s37_240g/p14606570/", "" };

    /*
    if (_argc > 2) {
        PageScraper page { _p_argv[1], _p_argv[2] };
    }
    else {
        PageScraper page { _p_argv[1], "" };
    }*/

    system("pause");
    system("cls");
}