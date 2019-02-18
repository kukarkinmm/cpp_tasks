//
// Created by michael on 11.02.19.
//

#include <gtest/gtest.h>

#include "tasks/user/user.h"
#include "tasks/user/userGroup.h"

TEST(User, eq) {
    User u(0, "John", "Doe");
    User copy(u);
    EXPECT_TRUE(u == copy);
}

TEST(User, binarySize) {
    User u(0, "Jane", "Doe");
    EXPECT_EQ(BinarySize<User>::size(u), 11);
}

TEST(UserGroup, eq) {
    UserGroup group(1);
    UserGroup copy(group);
    EXPECT_TRUE(group == copy);
}

TEST(UserGroup, binarySize) {
    User user = User(0);
    UserGroup userGroup = UserGroup(0, "Group", std::unordered_set<User>({user}));
    EXPECT_EQ(BinarySize<UserGroup>::size(userGroup), 20);
}
