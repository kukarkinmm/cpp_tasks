//
// Created by michael on 09.01.19.
//

#include <iostream>
#include <numeric>
#include <vector>

#include "iterator.h"

int main() {
    std::vector<double> v({1, 2, 3});
    auto i = iterator<double>(std::cout, " ");
    std::partial_sum(v.begin(), v.end(), i);
    return 0;
}
