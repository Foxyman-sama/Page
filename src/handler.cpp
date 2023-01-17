#include "handler.hpp"

size_t Handler::handle(const std::string &_ulr,
                       const std::string &_begin,
                       const std::string &_end,
                       const std::string &_formats,
                       const std::string &_directory,
                       const std::string &_avgformat) {
    try {
        std::string command { "if not exist " + _directory + " mkdir "  + _directory };
        system(command.c_str());

        std::shared_ptr<IBaseReceiver> p_htmlreceiver { new HTMLReceiver { } };
        Receiver                       receiver { p_htmlreceiver };
        auto                           p_str {
            receiver.receive(_ulr)
        };
        std::shared_ptr<IBaseFormater> p_htmlformater { new HTMLFormater { } };
        Formater                       formater { p_htmlformater };
        formater.format(p_str);

        std::shared_ptr<IBaseExtractor> p_htmlextractor { new HTMLExtractor { } };
        Extractor                       extractor { p_htmlextractor };
        auto                            extracted {
            extractor.extract(p_str, _begin, _end, -1, 300)
        };
        std::vector<std::string>        formats { };
        std::string                     temp { };
        for (size_t i { }; i < _formats.size(); ++i) {
            if (std::isalpha(_formats[i])) {
                while (std::isalpha(_formats[i])) {
                    temp += _formats[i++];
                }

                formats.emplace_back(temp);
                temp.clear();
            }
        }

        std::shared_ptr<IBaseFilterer> p_vecfilterer { new VectorFilterer { } };
        Filterer                       filterer { p_vecfilterer };
        auto                           filtered {
            filterer.filter(&extracted, formats)
        };
        auto                           fn { [&](std::vector<std::string> _filtered) {
            std::shared_ptr<IBaseDownloader> p_mediadownloader { new MediaDownloader { } };
            Downloader                       downloader { p_mediadownloader };
            for (size_t i { }; i < _filtered.size(); ++i) {
                downloader.download(_filtered[i], _avgformat, _directory + '/');
            }
        } };
        std::vector<std::future<void>> futures { };
        size_t                         count_of_thread {
            std::thread::hardware_concurrency()
        };
        size_t                         step { filtered.size() / count_of_thread };
        if (step > 0) {
            size_t iter { step };
            size_t last { };
            for (size_t i { }; i < count_of_thread; ++i) {
                if (i != count_of_thread - 1) {
                    std::vector<std::string> temp { filtered.begin() + last, filtered.begin() + iter };
                    futures.emplace_back(std::async(std::launch::async, fn, temp));
                }
                else {
                    std::vector<std::string> temp { filtered.begin() + last, filtered.end() };
                    futures.emplace_back(std::async(std::launch::async, fn, temp));
                }

                last  = iter;
                iter += step;
            }
            for (size_t i { }; i < futures.size(); ++i) {
                futures[i].get();
            }
        }
        else {
            fn(filtered);
        }

        return filtered.size();
    }
    catch (const std::exception &e) {
        qDebug() << e.what() << '\n';
        return UINT_MAX;
    }
}
