//
// Created by michael on 10.01.19.
//

#include <iostream>

#include "rotation.cpp"

int main() {
    std::pair<double, double> result = rotate(std::pair<double, double>(1.1, -0.2), 1);
    std::cout << result.first << " " << result.second << "\n";
    return 0;
}
