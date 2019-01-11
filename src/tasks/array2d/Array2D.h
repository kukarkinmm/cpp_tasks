//
// Created by michael on 08.01.19.
//

#ifndef CP_TASKS_ARRAY2D_H
#define CP_TASKS_ARRAY2D_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>


template <typename A>
class MaskedArray2D;

template <class T>
class Array2D {
    T** arr;
    size_t n, m;

    Array2D pairWiseTransform(const Array2D &a, const Array2D &b, std::function<T(T, T)> f) {
        Array2D result(a);
        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < m; ++j)
                result(i, j) = f(a(i, j), b(i, j));
        return result;
    }

    Array2D<bool> pairWiseLogic(const Array2D &a, const Array2D &b, std::function<T(T, T)> f) {
        Array2D<bool> result(a.rows(), a.columns());
        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < m; ++j)
                result(i, j) = f(a(i, j), b(i, j));
        return result;
    }

public:
    Array2D(size_t n, size_t m) : n(n), m(m) {
        arr = new T*[n];
        for (size_t i = 0; i < n; ++i) {
            arr[i] = new T[m];
        }
    }
    Array2D(size_t n, size_t m, const T &val) : Array2D(n, m) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                arr[i][j] = val;
            }
        }
    }

    ~Array2D() {
        for (size_t i = 0; i < n; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    Array2D(const Array2D &other) : n(other.n), m(other.m), arr(other.arr) {}
    Array2D(Array2D &&other) = default;

    Array2D &operator=(const Array2D &other) {
        asert(n == other.n && m = other.m);
        arr = other.arr;
        return *this;
    }

    size_t rows() const {
        return n;
    }

    size_t columns() const {
        return m;
    }

    Array2D operator+(const Array2D &b) {
        return pairWiseTransform(*this, b, std::plus<T>());
    }

    Array2D operator-(const Array2D &b) {
        return pairWiseTransform(*this, b, std::minus<T>());
    }

    Array2D operator*(const Array2D &b) {
        return pairWiseTransform(*this, b, std::multiplies<T>());
    }

    Array2D operator/(const Array2D &b) {
        return pairWiseTransform(*this, b, std::divides<T>());
    }

    Array2D<bool> operator==(const Array2D &b) {
        return pairWiseLogic(*this, b, std::equal_to<T>());
    }

    Array2D<bool> operator!=(const Array2D &b) {
        return pairWiseLogic(*this, b, std::not_equal_to<T>());
    }

    Array2D<bool> operator<(const Array2D &b) {
        return pairWiseLogic(*this, b, std::less<T>());
    }

    Array2D<bool> operator>(const Array2D &b) {
        return pairWiseLogic(*this, b, std::greater<T>());
    }

    Array2D<bool> operator>=(const Array2D &b) {
        return pairWiseLogic(*this, b, std::greater_equal<T>());
    }

    Array2D<bool> operator<=(const Array2D &b) {
        return pairWiseLogic(*this, b, std::less_equal<T>());
    }

    const T& operator()(size_t i, size_t j) const {
        return arr[i][j];
    }

    T &operator()(size_t i, size_t j) {
        return arr[i][j];
    }

    MaskedArray2D<T> operator()(const Array2D<bool> &mask) {
        return MaskedArray2D<T>(*this, mask);
    }
};

template <class T>
std::ostream &operator<<(std::ostream &stream, const Array2D<T> &array) {
    for(size_t i = 0; i < array.rows(); ++i) {
        for(size_t j = 0; j < array.columns(); ++j)
            stream << array(i, j) << " ";
        stream << "\n";
    }
    return stream;
}

#endif //CP_TASKS_ARRAY2D_H
