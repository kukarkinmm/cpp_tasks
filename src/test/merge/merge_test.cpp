//
// Created by michael on 11.02.19.
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

#include "tasks/merge/merge.h"

class merge_param {
public:
    std::vector<int> in;
};

class merge_test : public ::testing::TestWithParam<merge_param> {};

TEST_P(merge_test, merge) {
    const merge_param &p = GetParam();
    std::vector<int> v = p.in;
    std::vector<int> trueV = p.in;
    merge_sort(v.begin(), v.end());
    std::sort(trueV.begin(), trueV.end());
    EXPECT_EQ(trueV, v);
}

INSTANTIATE_TEST_CASE_P(one, merge_test, ::testing::Values(
        merge_param{{}, },
        merge_param{{1}, },
        merge_param{{1, 2}, },
        merge_param{{2, 1}, },
        merge_param{{2, 2}, },
        merge_param{{1, 2, 3, 4, 5, 6, 7}, },
        merge_param{{7, 6, 5, 4, 3, 2, 1}, },
        merge_param{{1, 4, 5, 2, 7, 3, 6}, },
        merge_param{{42, 3, 3, 2, 2, 1, 1},}));
