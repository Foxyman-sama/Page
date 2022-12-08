#include "userfunctions.hpp"

namespace user {
    std::string  connect(const std::string &_url) {
        Connector connector { };

        assert(connector.connect(_url) == true);

        return connector.getAnswer();
    }
    ParsedVector parse(const std::string &_answer,
                       const std::string &_formats) {
        Parser parser { std::regex { "(https|http)[^\"]+(" + _formats + ")[^\"|^?]*" } };

        assert(parser.parse(_answer) == true);

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

    void download(ParsedVector &_parsed) noexcept {
        Downloader downloader { };
        Indexer    indexer { "download/index.txt", _parsed.size() };

        for (auto &&el : _parsed) {
            Output output { _parsed };

            indexer.save(el.url_);

            if (!downloader.download(el)) {
                assert(tryDownload(downloader, el) == true);
            }
        }
    }
    void format(ParsedVector &_parsed) noexcept {
        Formater::format(_parsed);

        Checker  checker { "download" };

        checker.check(_parsed);
    }
}