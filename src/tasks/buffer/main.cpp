//
// Created by michael on 10.01.19.
//

#include <iostream>
#include <fstream>

#include "LineNumberBuffer.h"

int main() {
    std::ifstream in("test.txt");
    std::cin.rdbuf(in.rdbuf());
    LineNumberBuffer buff(std::cout.rdbuf());
    std::cout.rdbuf(&buff);
    std::cout << std::cin.rdbuf();
    return 0;
}
