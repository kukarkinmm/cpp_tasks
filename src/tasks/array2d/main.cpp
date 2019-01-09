//
// Created by michael on 08.01.19.
//

#include "Array2D.h"

int main() {
    Array2D<int> a(5, 5, 3);
    Array2D<int> b(5, 5, 3);
    auto c = a == b;
    std::cout << c;
    return 0;
}