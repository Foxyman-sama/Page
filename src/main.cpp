#include <iostream>
#include "scraplib.hpp"

int main(int   _argc,
         char *_p_argv[]) {  
    std::string url { };
    std::string begin { };
    std::string end { };
    short       offset { };
    std::cout << "url:   ";
    std::cin >> url;
    std::cout << "begin: ";
    std::cin >> begin;
    std::cout << "end:   ";
    std::cin >> end;
    std::cout << "offset: ";
    std::cin >> offset;
    try {
        std::shared_ptr<IBaseReceiver> p_dreceiver { new HTMLReceiver { } };
        Receiver                       receiver { p_dreceiver };
        auto                           p_str { receiver.receive(url) };
        std::shared_ptr<IBaseFormater> p_dformater { new HTMLFormater { } };
        Formater                       formater { p_dformater };
        formater.format(p_str);

        std::shared_ptr<IBaseExtractor> p_dextractor { new HTMLExtractor { } };
        Extractor                       extractor { p_dextractor };
        auto                            extracted { 
            extractor.extract(p_str, begin, end, offset)
        };
        std::shared_ptr<IBaseCacher>    p_dcacher { new XMLCacher { } };
        Cacher                          cacher { p_dcacher };
        cacher.write("https://www.youtube.com/", extracted);
        std::cout << "cached:\n";
        for (size_t i { }; i < extracted.size(); ++i) {
            std::cout << " [" << i << "#]\t" << extracted[i] << '\n';       
        }
    }
    catch (const std::exception &e) {
        system("cls");
        std::cerr << e.what() << '\n\n';
    }

    system("pause");
}