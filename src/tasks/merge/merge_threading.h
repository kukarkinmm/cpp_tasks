//
// Created by michael on 10.01.19.
//

#ifndef CP_TASKS_MERGE_THREADING_H
#define CP_TASKS_MERGE_THREADING_H

#include <vector>
#include <thread>
#include <iostream>

#include "merge.h"

template<typename It>
void merge_sort_threading(It begin, It end) {
    unsigned int numberOfThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    long size = std::distance(begin, end);
    if (size < 2)
        return;

    std::vector<std::pair<It, It>> parts(numberOfThreads);
    for (size_t i = 0; i < numberOfThreads; ++i) {
        parts[i].first = begin + i * size / numberOfThreads;
        parts[i].second = begin + (i + 1) * size / numberOfThreads;
        threads.emplace_back([](It i1, It i2) { return merge_sort(i1, i2);}, parts[i].first, parts[i].second);
    }
    for (std::thread &thread : threads)
        thread.join();
    while (parts.size() != 1) {
        for (size_t i = 0; i < parts.size() - 1; i += 2) {
            auto new_part = std::make_pair(parts[i].first, parts[i + 1].second);
            merge(parts[i].first, parts[i].second, parts[i + 1].second);
            parts.insert(parts.erase(parts.begin() + i, parts.begin() + i + 2), new_part);
        }
    }
}

#endif //CP_TASKS_MERGE_THREADING_H
