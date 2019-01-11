//
// Created by michael on 10.01.19.
//

#ifndef CP_TASKS_LINENUMBERBUFFER_H
#define CP_TASKS_LINENUMBERBUFFER_H

#include <streambuf>

class LineNumberBuffer : public std::streambuf {
    std::streambuf *buffer;

    bool flag = true;
    size_t index = 1;

public:
    explicit LineNumberBuffer(std::streambuf *buf);

protected:
    int overflow(int c) override;
    std::streamsize xsputn(const char_type* s, std::streamsize count) override;
};


#endif //CP_TASKS_LINENUMBERBUFFER_H
