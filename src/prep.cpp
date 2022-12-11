#include "prep.hpp"

void Prep::prepareString(std::string &_answer) noexcept {
    StringManipulator::deleteSymbols(_answer, { ' ', '\r', '\n', '\t' });
    StringManipulator::deleteRangeMatches(_answer, "<!", "</head>");
    StringManipulator::deleteRangeMatches(_answer, "<style>", "</style>");
    StringManipulator::replace(_answer, "&q;", "\"");
    StringManipulator::replace(_answer, "&quot;", "\"");
    StringManipulator::replace(_answer, "&#39;", "\'");

    _answer.shrink_to_fit();
}

