#ifndef VECTORMANIPULATOR_HPP
#define VECTORMANIPULATOR_HPP

#include <algorithm>
#include <vector>

class VectorManipulator {
public:
    template <typename T>
    static void deleteCopies(std::vector<T> &_vector) noexcept {
        std::sort(_vector.begin(), _vector.end());
        _vector.erase(std::unique(_vector.begin(), _vector.end()), _vector.end());
    }
};

#endif 
