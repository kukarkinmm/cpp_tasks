//
// Created by michael on 12.02.19.
//

#include <gtest/gtest.h>

#include "tasks/array2d/Array2D.h"
#include "tasks/array2d/MaskedArray2D.h"

TEST(Array2D, add) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<int> res(2, 3, 11);
    EXPECT_TRUE((a + b).equal_to(res));
}

TEST(Array2D, sub) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<int> res(2, 3, -1);
    EXPECT_TRUE((a - b).equal_to(res));
}

TEST(Array2D, div) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<int> res(2, 3, 0);
    EXPECT_TRUE((a / b).equal_to(res));
}

TEST(Array2D, mul) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<int> res(2, 3, 30);
    EXPECT_TRUE((a * b).equal_to(res));
}

TEST(Array2D, equal_to) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 5);
    EXPECT_TRUE(a.equal_to(b));
}

TEST(Array2D, equal) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, false);
    EXPECT_TRUE((a == b).equal_to(res));
}

TEST(Array2D, not_equal) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, true);
    EXPECT_TRUE((a != b).equal_to(res));
}

TEST(Array2D, less) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, true);
    EXPECT_TRUE((a < b).equal_to(res));
}

TEST(Array2D, less_equal) {
    Array2D<int> a(2, 3, 6);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, true);
    EXPECT_TRUE((a <= b).equal_to(res));
}

TEST(Array2D, greater) {
    Array2D<int> a(2, 3, 5);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, false);
    EXPECT_TRUE((a > b).equal_to(res));
}

TEST(Array2D, greater_equal) {
    Array2D<int> a(2, 3, 6);
    Array2D<int> b(2, 3, 6);
    Array2D<bool> res(2, 3, true);
    EXPECT_TRUE((a >= b).equal_to(res));
}

TEST(Mask, braces) {
    Array2D<int> a(5, 5, 3);
    Array2D<int> b(5, 5, 3);
    Array2D<bool> mask(5, 5, true);
    mask(1, 1) = false;
    mask(2, 2) = false;
    MaskedArray2D<int>(a, mask) = 400;
    Array2D<int> res(5, 5, 400);
    res(1, 1) = 3;
    res(2, 2) = 3;
    EXPECT_TRUE(a.equal_to(res));
}
