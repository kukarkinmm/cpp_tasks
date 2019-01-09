//
// Created by michael on 08.01.19.
//

#ifndef CP_TASKS_MESSAGE_H
#define CP_TASKS_MESSAGE_H

#include <ostream>

void message(std::ostream &stream, const char *str)
{
    while (*str) {
        if (*str == '%')
            if (*(str + 1) == '%')
                str++;
        stream << *str++;
    }
}


template <class T, class... Args>
void message(std::ostream &stream, const char *str, T &&arg, Args &&... args) {
    while (*str) {
        if (*str == '%') {
            if (*(str + 1) == '%') {
                str++;
            }
            else {
                stream << arg;
                str++;
                message(stream, str, args...);
                return;
            }
        }
        stream << *str++;
    }
}

#endif //CP_TASKS_MESSAGE_H
