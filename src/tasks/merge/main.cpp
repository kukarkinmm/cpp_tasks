//
// Created by michael on 09.01.19.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#include "merge.h"
#include "merge_threading.h"

int main() {
    std::vector<int> vec({7, 8, 2, 5, 1, 3, 4, 9, 6, 0});
    merge_sort(vec.begin() + 3, vec.end() - 3);
    for(size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";

    std::vector<int> v;
    v.resize(10000);
    for(int i = 0; i < 10000; ++i) {
        v[i] = i;
    }
    std::shuffle(v.begin(), v.end(), std::random_device());
    merge_sort_threading(v.begin(), v.end());
    for(size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    return 0;
}

