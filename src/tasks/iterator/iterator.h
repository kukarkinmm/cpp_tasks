//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_ITERATOR_H
#define CP_TASKS_ITERATOR_H

#include <iterator>

template <class T, class CharT = char, class Traits = std::char_traits<CharT>>
class iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    std::basic_ostream<CharT, Traits>* out_stream;
    const CharT* delim;

public:
    using char_type = CharT;
    using traits_type = Traits;
    using ostream_type = std::basic_ostream<CharT, Traits>;

    explicit iterator(ostream_type& s) : out_stream(&s), delim(0) {}
    iterator(ostream_type& s, const CharT* delimiter) : out_stream(&s), delim(delimiter) {}
    iterator(const iterator<T, CharT, Traits>& x) : out_stream(x.out_stream), delim(x.delim) {}
    ~iterator() = default;

    iterator<T, CharT, Traits>& operator=(const T& value) {
        *out_stream << value;
        if (delim!=0)
            *out_stream << delim;
        return *this;
    }
    
    iterator<T, CharT, Traits>& operator*() { return *this; }
    iterator<T, CharT, Traits>& operator++() { return *this; }
    const iterator<T, CharT, Traits> operator++(int) { return *this; }
};

#endif //CP_TASKS_ITERATOR_H
