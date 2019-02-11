//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_USERGROUP_H
#define CP_TASKS_USERGROUP_H

#include <unordered_set>

#include "user.h"

class UserGroup {
    unsigned int id;
    std::string groupName;
    std::unordered_set<User> users;

public:
    explicit UserGroup(unsigned int id);
    UserGroup(unsigned int id, std::string name, std::unordered_set<User> users_);

    bool operator==(const UserGroup &userGroup) const;

    unsigned int getId() const;
    std::string getName() const;
    std::unordered_set<User> getUsers() const;
};

namespace std {
    template <>
    class hash<UserGroup> {
    public:
        size_t operator()(const UserGroup &userGroup) const;
    };
}

template <>
class BinarySize<UserGroup> {
public:
    static size_t size(const UserGroup &userGroup);
};

#endif //CP_TASKS_USERGROUP_H
