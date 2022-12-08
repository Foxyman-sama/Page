#include "cacher.hpp"

Cacher::Cacher(const std::string &_folder, 
               std::string       &_file) noexcept {
    StringManipulator::deleteSymbols(_file);

    file_ = _folder + '\\' + _file + ".txt";
}

ParsedVector Cacher::read() noexcept {
    ParsedVector parsed { };
    std::string  url { };
    std::string  format { };

    while (reader_ >> url >> format) {
        parsed.emplace_back(url, format);

        StringManipulator::deleteSymbols(parsed.back().format_);
    }

    reader_.close();

    return parsed;
}

void Cacher::write(const ParsedVector &_parsed) noexcept { 
    system("mkdir cache");

    cacher_.open(file_);

    size_t size { _parsed.size() };

    for (size_t i { }; i < size; ++i) {
        cache(_parsed[i].url_, _parsed[i].format_);
    }

    cacher_.close();
}
