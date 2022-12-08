#ifndef INDEXER_HPP
#define INDEXER_HPP

#include "saver.hpp"

class Indexer final : public Saver  {
public:
    explicit Indexer(const std::string &_name,
                     size_t             _size) noexcept :
        Saver { _name } {
        saver_ << "Размер: " << _size << '\n';
    }

    virtual void save(const std::string &_text) noexcept override;
};

#endif 