//
// Created by michael on 09.01.19.
//

#include "userGroup.h"

UserGroup::UserGroup(unsigned int id) : id(id), groupName(std::string("group" + 1)), users() {}

UserGroup::UserGroup(unsigned int id, std::string name, std::unordered_set<User> users)
                        : id(id), groupName(std::move(name)), users(std::move(users)) {}

bool UserGroup::operator==(const UserGroup &userGroup) const {
    return (id == userGroup.id && groupName == userGroup.groupName && users == userGroup.users);
}

unsigned int UserGroup::getId() const {
    return id;
}

std::string UserGroup::getName() const {
    return groupName;
}

std::unordered_set<User> UserGroup::getUsers() const {
    return users;
}

size_t std::hash<UserGroup>::operator()(const UserGroup &userGroup) const {
    return ((hash<string>()(userGroup.getName()) << 1) >> 1)
           ^ (hash<unsigned int>()(userGroup.getId()) << 1);
}

size_t BinarySize<UserGroup>::size(const UserGroup &userGroup) {
    size_t sizeOfUsers = 0;
    for(User user : userGroup.getUsers())
        sizeOfUsers += BinarySize<User>::size(user);
    return sizeof(userGroup.getId()) + userGroup.getName().size() + sizeOfUsers;
}
