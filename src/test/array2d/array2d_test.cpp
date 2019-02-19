//
// Created by michael on 12.02.19.
//

#include <gtest/gtest.h>

#include "tasks/array2d/Array2D.h"
#include "tasks/array2d/MaskedArray2D.h"

class bool_array2d_param {
public:
    Array2D<bool> test;
    Array2D<bool> result;
};

class bool_array2d_test : public  ::testing::TestWithParam<bool_array2d_param> {};

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

INSTANTIATE_TEST_CASE_P(_, bool_array2d_test, ::testing::Values(
        bool_array2d_param{(Array2D<int>(2, 3, 5) == Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) == Array2D<int>(2, 3, 6)), Array2D<bool>(2, 3, false)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) != Array2D<int>(2, 3, 0)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) != Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, false)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) < Array2D<int>(2, 3, 6)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) < Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, false)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) <= Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 7) <= Array2D<int>(2, 3, 6)), Array2D<bool>(2, 3, false)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) > Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, false)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) > Array2D<int>(2, 3, -1)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) >= Array2D<int>(2, 3, 5)), Array2D<bool>(2, 3, true)},
        bool_array2d_param{(Array2D<int>(2, 3, 5) >= Array2D<int>(2, 3, 6)), Array2D<bool>(2, 3, false)}
));

TEST_P(bool_array2d_test, _) {
    const auto &p = GetParam();
    EXPECT_TRUE(p.test.equal_to(p.result));
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
