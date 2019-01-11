//
// Created by michael on 10.01.19.
//

#include <gtest/gtest.h>

#include "tasks/rotation/rotation.cpp"

TEST(rotate_test, one) {
    std::pair<double,double> result = rotate(std::pair<double,double>(1.1, -0.2), 1);
    EXPECT_EQ(result.first, 0.2);
    EXPECT_EQ(result.second, 1.1);
}

TEST(rotate_test, two) {
    std::pair<double,double> result = rotate(std::pair<double,double>(1.1, -0.2), 2);
    EXPECT_EQ(result.first, -1.1);
    EXPECT_EQ(result.second, 0.2);
}

TEST(rotate_test, three) {
    std::pair<double,double> result = rotate(std::pair<double,double>(1.1, -0.2), 3);
    EXPECT_EQ(result.first, -0.2);
    EXPECT_EQ(result.second, -1.1);
}

TEST(rotate_test, four) {
    std::pair<double,double> result = rotate(std::pair<double,double>(1.1, -0.2), 4);
    EXPECT_EQ(result.first, 1.1);
    EXPECT_EQ(result.second, -0.2);
}

