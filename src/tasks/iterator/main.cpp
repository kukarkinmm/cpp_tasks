//
// Created by michael on 09.01.19.
//

#include <iostream>
#include <numeric>
#include <sstream>

#include "iterator.h"

int main() {
    std::istringstream str("0.1 0.2 0.3 0.4");
    std::partial_sum(std::istream_iterator<double>(str),
                     std::istream_iterator<double>(),
                     std::ostream_iterator<double>(std::cout, " "));
    return 0;
}
