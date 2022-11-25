#include "pagescraper.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    PageScraper page { "https://yt3.ggpht.com/ytc/AMLnZu_62Edd2usbc2P47Cz76FVX71wiSGSeqOif0sF1Zw=s88-c-k-c0x00ffffff-no-rj", "png" };

    system("pause");
}