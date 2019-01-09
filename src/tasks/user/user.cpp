//
// Created by michael on 09.01.19.
//

#include "user.h"

User::User(unsigned int id) : id(id), name(std::string("John")), lastName(std::string("Doe")) {}
User::User(unsigned int id, std::string name, std::string lastName) :
                id(id), name(std::move(name)), lastName(std::move(lastName)) {}

bool User::operator==(const User &user) const {
    return (id == user.id && name == user.name && lastName == user.lastName);
}

unsigned int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getLastName() const {
    return lastName;
}

size_t std::hash<User>::operator()(const User &user) const {
    return ((hash<string>()(user.getName())
             ^ (hash<string>()(user.getLastName()) << 1)) >> 1)
           ^ (hash<unsigned int>()(user.getId()) << 1);
}
