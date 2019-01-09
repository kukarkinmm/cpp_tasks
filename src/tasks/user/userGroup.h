//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_USERGROUP_H
#define CP_TASKS_USERGROUP_H

#include <unordered_set>

#include "user.h"

class UserGroup {
    std::string groupName;
    unsigned int id;
    std::unordered_set<User> users;

public:
    explicit UserGroup(unsigned int id);
};

#endif //CP_TASKS_USERGROUP_H
