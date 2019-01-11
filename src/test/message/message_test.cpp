//
// Created by michael on 08.01.19.
//

#include <gtest/gtest.h>
#include <string>
#include <sstream>

#include "tasks/message/message.h"

TEST(MessageTest, format) {
std::stringstream test_str;
message(test_str, "% + % = %\n", 'a', 2, 3.0);

EXPECT_TRUE(std::string("a + 2 = 3\n") == test_str.str());
}

TEST(MessageTest, argsOne) {
std::stringstream test_str;
message(test_str, "% + % = %\n", 'a', 2, 3.0, "oneMore");

EXPECT_TRUE(std::string("a + 2 = 3\n") == test_str.str());
}

TEST(MessageTest, argsTwo) {
std::stringstream test_str;
message(test_str, "% + % = %\n", 'a', 2);

EXPECT_TRUE(std::string("a + 2 = %\n") == test_str.str());
}
