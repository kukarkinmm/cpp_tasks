//
// Created by michael on 11.02.19.
//

#include <gtest/gtest.h>
#include <string>

#include "tasks/buffer/LineNumberBuffer.h"

struct buffer_param {
    std::string in;
    std::string out;
};

class buffer_test : public ::testing::TestWithParam<buffer_param> {};

TEST_P(buffer_test, _) {
    const auto &p = GetParam();
    std::stringstream str;
    std::ostream stream(str.rdbuf());
    LineNumberBuffer buffer(stream.rdbuf());
    stream.rdbuf(&buffer);
    stream << p.in;
    EXPECT_EQ(p.out, str.str());
}

INSTANTIATE_TEST_CASE_P(_, buffer_test, ::testing::Values(
        buffer_param{"", ""},
        buffer_param{"Hello, World!", "1Hello, World!\n"},
        buffer_param{"\n", "1\n"}));
