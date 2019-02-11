//
// Created by michael on 11.02.19.
//

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "tasks/iterator/iterator.h"

struct iterator_param {
    std::vector<int> in;
    std::string out;
};

class iterator_test : public ::testing::TestWithParam<iterator_param> {};

TEST_P(iterator_test, _) {
    const auto &p = GetParam();
    std::stringstream stream;
    auto iter = iterator<int>(stream);
    std::copy(p.in.begin(), p.in.end(), iter);
    EXPECT_EQ(stream.str(), p.out);
}

INSTANTIATE_TEST_CASE_P(_, iterator_test, ::testing::Values(
                iterator_param{{1, 2, 3, 4}, "1234"},
                iterator_param{{}, ""},
                iterator_param{{1, 2, 3, 4, 5, 6, 7}, "246"},
                iterator_param{{1, 2, 3}, "3"},
                iterator_param{{1, 2}, ""}));