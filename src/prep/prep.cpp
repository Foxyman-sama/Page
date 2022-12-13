#include "prep.hpp"

void Prep::prepareAnswer(std::string &_answer) noexcept {
    StringManipulator::deleteSymbols(_answer, { ' ', '\r', '\n', '\t' });
    StringManipulator::replace(_answer, "&q;", "\"");
    StringManipulator::replace(_answer, "&quot;", "\"");
    StringManipulator::replace(_answer, "&#39;", "\'");
    StringManipulator::replace(_answer, "\\u002F", "/");
    StringManipulator::replace(_answer, "\\/", "/");
    StringManipulator::replace(_answer, "\\u0026", "&");
    StringManipulator::replace(_answer, "\\u003d", "=");
    StringManipulator::replace(_answer, "\\u003C", "<");
    StringManipulator::replace(_answer, "\\u003E", ">");
    StringManipulator::deleteRangeMatches(_answer, "<!", "</head>");
    StringManipulator::deleteRangeMatches(_answer, "<style", "</style>");
    StringManipulator::deleteRangeMatches(_answer, "<button", "</button>");

    _answer.shrink_to_fit();
}

