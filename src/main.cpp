#include "connector.hpp"
#include "parser.hpp"

int main(int   _argc,
         char *_p_argv[]) {
    setlocale(0, ".UTF8");   

    Connector connector { };

    if (!connector.connect("https://www.youtube.com/")) {
        std::cerr << "Get answer problem. Try in another time.\n";

        system("pause");

        return -1;
    }

    Parser parser { std::regex { "(https|http)[^\"]+(\.png|\.jpg|-rj)[^\"|^?]*" } };

    if (!parser.parse(connector.getAnswer(), ".png")) {
        std::cerr << "Get parser problem. Try in another time.\n";

        system("pause");

        return -2;
    }


    system("pause");
}