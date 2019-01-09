//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_USER_H
#define CP_TASKS_USER_H

#include <iostream>

class User {
    unsigned int id;
    std::string name, lastName;

public:
    explicit User(unsigned int id);
    User(unsigned int id, std::string name, std::string lastName);

    bool operator==(const User &user) const;

    unsigned int getId() const;
    std::string getName() const;
    std::string getLastName() const;
};

namespace std {
    template <>
    class hash<User> {
    public:
        size_t operator()(const User &user) const;
    };
}

#endif //CP_TASKS_USER_H
