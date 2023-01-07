#include "receiver.hpp"

StringPtr Receiver::receive(const std::string &_url) {
    auto p_answer { p_receiver_->sendRequest(_url) };
    if (!p_answer.get()) {
        excp(Cause::BADREQUEST);
    }

    return p_answer;
}
