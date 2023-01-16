#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include "interface/ibasereceiver.hpp"
#include "scrapexception.hpp"

template
class SCRAP_API std::shared_ptr<IBaseReceiver>;

// @brief Class used to receive information
class SCRAP_API Receiver {
private:
    std::shared_ptr<IBaseReceiver> p_receiver_;

public:
    Receiver(const std::shared_ptr<IBaseReceiver> &_p_derived) noexcept
        : p_receiver_ { _p_derived } { }

    // @brief Used to get information
    // @param _url - from where to get
    // @return Acquired information 
    StringPtr receive(const std::string &_url);

    void setStrategy(const std::shared_ptr<IBaseReceiver> &_p_derived) noexcept {
        p_receiver_ = _p_derived;
    }
};

#endif 