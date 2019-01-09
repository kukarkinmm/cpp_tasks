//
// Created by michael on 08.01.19.
//

#include <iostream>

#include "guard.h"

void print_hex(int i) {
    Guard g(std::cout);
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    std::cout << i;
}

int main() {
    print_hex(10);
    return 0;
}