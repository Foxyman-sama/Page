#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <QDebug>
#include "receiver.hpp"
#include "formater.hpp"
#include "extractor.hpp"
#include "filterer.hpp"
#include "downloader.hpp"
#include "htmlreceiver.hpp"
#include "htmlformater.hpp"
#include "htmlextractor.hpp"
#include "vectorfilterer.hpp"
#include "mediadownloader.hpp"

class Handler {
public:
    static size_t handle(const std::string &_ulr,
                         const std::string &_begin,
                         const std::string &_end,
                         const std::string &_formats,
                         const std::string &_directory,
                         const std::string &_avgformat);
};

#endif
