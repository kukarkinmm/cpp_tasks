//
// Created by michael on 08.01.19.
//

#include <fstream>
#include <algorithm>
#include <random>

#include "Vector.h"

int main() {
//    Vector<int> v(3, 3);
//    v.push_back(4);
//    v.push_back(4);
//    v.push_back(4);
//    v.push_back(5);
//    v.push_back(5);
//    for(const auto & i : v)
//        std::cout << i << " ";
//    std::cout << "\n";
//    v.erase(v.begin());
//    for(const auto & i : v)
//        std::cout << i << " ";
    Vector<std::ofstream> vec;
    vec.push_back(std::ofstream("a.txt"));
    vec.push_back(std::ofstream("b.txt"));
    vec.push_back(std::ofstream("c.txt"));

    std::shuffle(vec.begin(), vec.end(), std::random_device());
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] << i;
        vec[i].close();
    }
    return 0;
}
