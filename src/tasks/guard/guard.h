//
// Created by michael on 08.01.19.
//

#ifndef CP_TASKS_GUARD_H
#define CP_TASKS_GUARD_H

#include <ostream>

class Guard {
    std::ostream &stream;
    std::ios::fmtflags flags;
    char fill;

    Guard(const Guard &) = delete;
    Guard &operator=(const Guard &) = delete;

public:
    Guard(std::ostream &other);
    ~Guard();
};

#endif //CP_TASKS_GUARD_H
