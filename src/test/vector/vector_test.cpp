//
// Created by michael on 01.02.19.
//

#include <gtest/gtest.h>

#include "vector/Vector.h"

template <class T>
class VectorTest : ::testing::Test {

};

TEST(Vector, defaultConstructor) {
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
}

TEST(Vector, sizeConstructor) {
    Vector<int> v(5);
    EXPECT_EQ(v.size(), 5);
}

TEST(Vector, sizeDefElConstructor) {
    Vector<int> v(5, 2);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v[2], 2);
}

TEST(Vector, copy) {
    Vector<int> origin(5, 2);
    Vector<int> copy(origin);

    EXPECT_EQ(origin.size(), copy.size());

    copy.push_back(7);

    EXPECT_EQ(origin[4], 2);
    EXPECT_EQ(copy[5], 7);
}

TEST(Vector, move) {
    Vector<int> origin(5, 2);
    Vector<int> moved(std::move(origin));

    EXPECT_EQ(moved.size(), 5);
}

TEST(Vector, equalCopy) {
    Vector<int> origin(5, 2);
    Vector<int> copy(7, 7);
    copy = origin;

    EXPECT_EQ(origin.size(), copy.size());

    origin.push_back(9);

    EXPECT_EQ(origin.size(), 6);
    EXPECT_EQ(copy.size(), 5);
    EXPECT_EQ(origin[0], 2);
    EXPECT_EQ(copy[5], 9);
}

TEST(Vector, equalMove) {
    Vector<int> origin(5, 2);
    Vector<int> copy(7, 7);
    copy = std::move(origin);

    EXPECT_EQ(copy.size(), 5);
    EXPECT_EQ(origin.size(), 0);
    EXPECT_EQ(copy[0], 2);
}

TEST(Vector, size) {
    Vector<double> v(70);
    EXPECT_EQ(v.size(), 70);
}

TEST(Vector, pushBackCopy) {
    Vector<double> v;
    double a = 2.5;
    v.push_back(a);

    EXPECT_EQ(v.size(), 1);
    EXPECT_DOUBLE_EQ(a, 2.5);
    EXPECT_DOUBLE_EQ(v[0], a);
}

TEST(Vector, pushBackMove) {
    Vector<double> v;
    v.push_back(2.5);

    EXPECT_EQ(v.size(), 1);
    EXPECT_DOUBLE_EQ(v[0], 2.5);
}

TEST(Vector, pop_back) {
    Vector<int> v(5, 2);
    v.pop_back();

    EXPECT_EQ(v.size(), 4);
}

TEST(Vector, eraseOne) {
    Vetor<int> v({0, 1, 2, 3});
    v.erase(v.begin() + 1);

    EXPECT_EQ(v.size(), 3);
}

TEST(Vector, eraseMore) {
    Vetor<int> v({0, 1, 2, 3, 4});
    v.erase(v.begin() + 1, v.begin() + 3);

    EXPECT_EQ(v.size(), 2);
}
