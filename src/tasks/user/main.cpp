//
// Created by michael on 09.01.19.
//

#include "user.h"
#include "userGroup.h"

int main() {
    User user = User(0);
    UserGroup userGroup = UserGroup(0, "Group", std::unordered_set<User>({user}));
    std::cout << BinarySize<User>::size(user) << "\n";
    std::cout << BinarySize<UserGroup>::size(userGroup) << "\n";
    return 0;
}
