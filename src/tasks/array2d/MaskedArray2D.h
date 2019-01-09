//
// Created by michael on 08.01.19.
//

#ifndef CP_TASKS_MASKEDARRAY2D_H
#define CP_TASKS_MASKEDARRAY2D_H

#include "Array2D.h"

template <typename A>
class Array2D;

template <class T>
class MaskedArray2D {
    Array2D<T> &array;
    const Array2D<bool> &mask;

public:
    MaskedArray2D(Array2D<T> &arr, const Array2D<bool> &mask) : array(arr), mask(mask) {}
    Array2D<T> operator=(T val) {
        for(size_t i = 0; i < array.rows(); ++i)
            for(size_t j = 0; j < array.columns(); ++j)
                if (mask(i, j))
                    array(i, j) = val;
        return array;
    }
};

#endif //CP_TASKS_MASKEDARRAY2D_H
