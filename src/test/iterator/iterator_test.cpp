//
// Created by michael on 11.02.19.
//

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

#include "tasks/iterator/iterator.h"

struct iterator_param {
    std::vector<double> in;
    std::string out;
};

class iterator_test : public ::testing::TestWithParam<iterator_param> {};

TEST_P(iterator_test, _) {
    const auto &p = GetParam();
    std::vector<double> v;
    std::stringstream stream;
    auto iter = iterator<double>(stream, " ");
    std::partial_sum(p.in.begin(), p.in.end(), iter);
    EXPECT_EQ(stream.str(), p.out);
}

INSTANTIATE_TEST_CASE_P(_, iterator_test, ::testing::Values(
                iterator_param{{0.1, 0.2, 0.3, 0.4}, "0.1 0.3 0.6 1 "},
                iterator_param{{}, ""},
                iterator_param{{1, 2, 3}, "1 3 6 "}));