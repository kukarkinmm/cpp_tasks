//
// Created by michael on 08.01.19.
//

#include "Array2D.h"
#include "MaskedArray2D.h"

int main() {
    Array2D<int> a(5, 5, 3);
    Array2D<int> b(5, 5, 3);
    Array2D<bool> mask(5, 5, true);
    mask(1, 1) = false;
    mask(2, 2) = false;
    MaskedArray2D<int>(a, mask) = 400;
    std::cout << a;
    return 0;
}