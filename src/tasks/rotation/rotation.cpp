//
// Created by michael on 10.01.19.
//

#include <utility>

std::pair<double, double> rotate(const std::pair<double, double> &vector, unsigned int angle) {
    if (angle % 4 == 0)
        return vector;
    if (angle % 4 == 1)
        return std::pair<double, double>(-vector.second, vector.first);
    if (angle % 4 == 2)
        return std::pair<double, double>(-vector.first, -vector.second);
    if (angle % 4 == 3)
        return std::pair<double, double>(vector.second, -vector.first);
    return std::pair<double, double>();
}
