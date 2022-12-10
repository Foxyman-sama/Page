#include "prep.hpp"

void Prep::prepareString(std::string &_answer) noexcept {
    StringManipulator::deleteSymbols(_answer, { ' ' });

    _answer.erase(_answer.begin(), _answer.begin() + _answer.find("</head>") + 7);
    _answer.shrink_to_fit();
}

