//
// Created by michael on 08.01.19.
//

#ifndef COMPONENTALPROGRAMMING_VECTOR_H
#define COMPONENTALPROGRAMMING_VECTOR_H

#include <iostream>

template <class T>
class Vector {
    using iterator = T*;
    T *v;
    size_t size_, capacity_;

    void reallocate() {
        capacity_ *= 2;
        T *temp = new T[capacity_];
        std::swap(temp, v);
        for(size_t i = 0; i < size_; ++i)
            v[i] = std::move(temp[i]);
        delete[] temp;
    }

public:
    Vector() : size_(0) , capacity_(10), v(new T[10]) {};
    explicit Vector(size_t n) : size_(n), capacity_(2 * n), v(new T[2 * n]) {
        for (size_t i = 0; i < n; ++i)
            v[i] = T();
    }

    Vector(size_t n, const T &val) : size_(n), capacity_(2 * n), v(new T[2 * n]) {
        for (size_t i = 0; i < n; ++i)
            v[i] = val;
    }

    Vector(std::initializer_list<T> &il) : size_(il.size()), capacity_(il.size() * 2) {
        for (size_t i = 0; i < il.size(); ++i)
            v[i] = il[i];
    }

    Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_), v(new T[other.capacity_]) {
        for (size_t i = 0; i < size_; ++i)
            v[i] = other.v[i];
    }

    Vector(Vector &&other) noexcept : v(nullptr), size_(0), capacity_(0) {
        this->swap(other);
    }

    Vector &operator=(const Vector &other) {
        if (this != other) {
            delete[] v;
            size_ = other.size_;
            capacity_ = other.capacity_;
            v = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
                v[i] = other.v[i];
        }
        return *this;
    }

    Vector &operator=(Vector &&other) noexcept {
        delete[] v;
        v = nullptr;
        size_ = 0;
        capacity_ = 0;
        this->swap(other);
        return *this;
    }

    const T& operator[](size_t index) const {
        return *(v + index);
    }

    T &operator[](size_t index) {
        return *(v + index);
    }

    ~Vector() {
        delete[] v;
    }

    void swap(Vector &other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(v, other.v);
    }

    void pop_back() {
        size_--;
    }

    void push_back(const T &val) {
        if (size_ >= capacity_)
            reallocate();
        *(v + size_) = val;
        size_++;
    }

    void push_back(T &&val) {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            T *temp = new T[capacity_];
            std::swap(temp, v);
            for (size_t i = 0; i < size_; ++i)
                v[i] = std::move(temp[i]);
            delete[] temp;
        }
        *(v + size_) = std::move(val);
        size_++;
    }

    void erase(iterator first, iterator last) {
        for(iterator i = first; i < end() - (last - first); ++i) {
            *i = *(i + (last - first));
        }
        size_ -= last - first;
    }

    void erase(iterator pos) {
        erase(pos, pos + 1);
    }

    size_t size() const {
        return size_;
    }

    iterator begin() const {
        return v;
    }

    iterator end() const {
        return v + size_;
    }
};

namespace std {
    template <typename T>
    void swap(Vector<T> &one, Vector<T> &two){
        one.swap(two);
    }
}

#endif //COMPONENTALPROGRAMMING_VECTOR_H
