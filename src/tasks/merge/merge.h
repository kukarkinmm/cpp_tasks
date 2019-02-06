//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_MERGE_H
#define CP_TASKS_MERGE_H

#include <iterator>
#include <vector>

template<typename It>
void merge(It begin, It mid, It end) {
    std::vector<typename It::value_type> v;
    v.reserve(std::distance(begin, end));
    It left{begin}, right{mid};

    while (left != mid && right != end)
        v.push_back((*left <= *right) ? *left++ : *right++);

    v.insert(v.end(), left, mid);
    v.insert(v.end(), right, end);

    std::move(v.begin(), v.end(), begin);
}

template<typename It>
void merge_sort(It begin, It end) {
    long size = std::distance(begin, end);
    if (size < 2)
        return;

    It mid = std::next(begin, size / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);

    merge(begin, mid, end);
}

#endif //CP_TASKS_MERGE_H
