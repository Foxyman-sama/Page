#ifndef SAVER_HPP
#define SAVER_HPP

#include <fstream>

class Saver {
private:
    std::ofstream save_;

public:
    explicit Saver(const std::string &_name) noexcept {
        save_.open(_name, std::ios_base::binary);
    }
    ~Saver() noexcept {
        save_.close();
    }

    std::ofstream &getSave() noexcept {
        return save_;
    }

};

#endif 