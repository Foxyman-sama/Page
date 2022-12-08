#include "cacher.hpp"

Cacher::Cacher(const std::string &_folder, 
               std::string       &_file) noexcept {
    StringManipulator::deleteSymbols(_file);

    file_ = _folder + '\\' + _file + ".txt";
}

bool         Cacher::isCached() noexcept {  
    reader_.open(file_);

    bool is_open { reader_.is_open() };

    reader_.close();

    return is_open;
}
ParsedVector Cacher::read() noexcept {
    ParsedVector parsed { };
    std::string  url { };
    std::string  format { };

    reader_.open(file_);

    assert(reader_.is_open() == true);

    while (std::getline(reader_, url)) {
        parsed.emplace_back(url, "");

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
        if (i == size - 1) {
            cache(_parsed[i].url_);

            break;
        }

        cache(_parsed[i].url_ + '\n');
    }

    cacher_.close();
}
