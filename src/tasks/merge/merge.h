//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_MERGE_H
#define CP_TASKS_MERGE_H

#include <iterator>
#include <vector>

template<typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end) {
    std::vector<typename It::value_type> v;
    It it_l{begin}, it_r{mid};
    const It it_mid{mid}, it_end{end};

    while (it_l != it_mid && it_r != it_end)
        v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);

    v.insert(v.end(), it_l, it_mid);
    v.insert(v.end(), it_r, it_end);

    return std::move(v);
}

template<typename It>
void merge_sort(It begin, It end) {
    auto size = std::distance(begin, end);
    if (size < 2)
        return;

    auto mid = std::next(begin, size / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);

    auto &&v = merge(begin, mid, end);
    std::move(v.cbegin(), v.cend(), begin);
}

#endif //CP_TASKS_MERGE_H
