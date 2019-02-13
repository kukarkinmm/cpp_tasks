//
// Created by michael on 09.01.19.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

#include "merge.h"
#include "merge_threading.h"

int main() {
    std::vector<std::pair<size_t, size_t>> merge_results;
    merge_results.reserve(10);
    std::vector<std::pair<size_t, size_t>> threading_results(merge_results);

    size_t n = 10;
    for(size_t i = 0; i < 7; ++i) {
        std::vector<int> v;
        v.reserve(n);

        for(int i = 0; i < n; ++i) {
            v.push_back(i);
        }
        std::shuffle(v.begin(), v.end(), std::random_device());
        auto start = std::chrono::system_clock::now();
        merge_sort(v.begin(), v.end());
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
        merge_results.emplace_back(std::make_pair(n, t));
        std::cout << "Ordinary: " << n << " " << t << "\n";
        std::shuffle(v.begin(), v.end(), std::random_device());
        start = std::chrono::system_clock::now();
        merge_sort_threading(v.begin(), v.end());
        t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count();
        threading_results.emplace_back(std::make_pair(n, t));
        std::cout << "Threading: " << n << " " << t << "\n";

        n *= 10;
    }

    std::ofstream out("../out.txt");
    for (size_t i = 0; i < 7; ++i) {
        out << merge_results[i].first << " " << merge_results[i].second << " " << threading_results[i].second << "\n";
    }
    out.close();
    return 0;
}

