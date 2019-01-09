//
// Created by michael on 08.01.19.
//

#include "guard.h"

Guard::Guard(std::ostream &other) : stream(other) {
    flags = other.flags();
    fill = other.fill();
}

Guard::~Guard() {
    stream.flags(flags);
    stream.fill(fill);
}
