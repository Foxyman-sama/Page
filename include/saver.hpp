#ifndef SAVER_HPP
#define SAVER_HPP

#include <fstream>

class Saver {
private:
    std::ofstream saver_;

public:
    explicit Saver(const std::string &_name) noexcept {
        saver_.open("download/" + _name, std::ios_base::binary);
    }
    ~Saver() noexcept {
        saver_.close();
    }

    std::ofstream &getSaver() noexcept {
        return saver_;
    }

};

#endif 