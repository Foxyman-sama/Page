#include "userfunctions.hpp"

namespace scrap {
    std::string  connect(const std::string &_url) {
        Connector connector { };

#ifdef NDEBUG
        connector.connect(_url);
#else
        assert(connector.connect(_url) == true);
#endif

        return connector;
    }
    ParsedVector parse(const std::string &_answer,
                       const std::string &_formats) {
        Parser parser { std::regex { "(\\W|^)((?:https?|//){1}[^\"]{10,300}(?:" + _formats
                                                                                + "))(\\W|$)" } };
       
#ifdef NDEBUG
        parser.parse(_answer);
#else
        assert(parser.parse(_answer) == true);
#endif

        return parser.getParsed();
    }
    bool         tryDownload(Downloader         &_downloader,
                             const ParsedResult &_parsed) {
        size_t try_count { };

        while (try_count != MAX_TRY_COUNT) {
            system("cls");

            std::cout << "Try to download: " << _parsed.url_ << '\n';

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            if (_downloader.download(_parsed)) {
                break;
            }
            else if (++try_count == 5) {
                std::cout << "Can`t download " << _parsed.url_ << '\n';
                std::cout << "Try later.\n\n";

                return false;
            }
        } 

        return true;
    }

    void start() noexcept {
        std::string url { };

        std::cout << "¬ведите сайт: ";
        std::getline(std::cin, url);

        scraping(url);
    }
    void scraping(std::string &_url) noexcept {
        system("if not exist download mkdir download");
        system("cls");

        ParsedVector parsed { };

        if (!Cacher::isCached(_url)) {
            std::string answer { scrap::connect(_url) };

            scrap::prepare(answer);

            parsed = scrap::parse(answer, FORMATS.data());

            Cacher cacher { _url, Cacher::OpenType::ONWRITE };
            cacher.write(parsed);
        }
        else {
            Cacher cacher { _url, Cacher::OpenType::ONREAD };
            cacher.read(parsed);
        }

        scrap::format(parsed);

        if (parsed.size()) {
            scrap::download(parsed);
        }
    }
    void download(ParsedVector &_parsed) noexcept {
        Downloader downloader { };
        Print      printer { _parsed.size() };
        Indexer    indexer { "download/index.txt", _parsed.size() };
        indexer.write(_parsed);

        for (auto &&el : _parsed) {
            if (!downloader.download(el)) {
                Throw(ErrorCatcher::Status::CACHE_ERROR);
            }

            printer.print();
        }
    }
    void prepare(std::string &_answer) noexcept {
        Prep::prepareAnswer(_answer);
    }
    void format(ParsedVector &_parsed) noexcept {
        Formater::format(_parsed);

        Checker checker { "download" };
        checker.read(_parsed);
    }
}