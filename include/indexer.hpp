#ifndef INDEXER_HPP
#define INDEXER_HPP

#include "ioutput.hpp"

class Indexer final : public IOutput  {
public:
    virtual bool write(const std::string &_data) noexcept override;

public:
    explicit Indexer(const std::string &_name,
                     size_t             _size) noexcept;
    ~Indexer() noexcept {
        fout_.close();
    }
};

#endif 