#ifndef SAVER_HPP
#define SAVER_HPP

#include <fstream>

class Saver {
protected:
    std::ofstream saver_;

protected:
    virtual void save(const std::string &_text) noexcept;

public:
    explicit Saver(const std::string &_name) noexcept {
        saver_.open(_name, std::ios_base::binary);
    }
    ~Saver() noexcept {
        saver_.close();
    }

    std::ofstream &getSaver() noexcept {
        return saver_;
    }

};

#endif 