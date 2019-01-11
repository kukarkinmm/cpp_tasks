//
// Created by michael on 10.01.19.
//

#include "LineNumberBuffer.h"

LineNumberBuffer::LineNumberBuffer(std::streambuf *buf) : buffer(buf) {}

int LineNumberBuffer::overflow(int c) {
    if (flag)
        buffer->sputn((std::to_string(index++) + " ").data(), std::to_string(index).length() + 1);
    flag = (c == '\n');
    return buffer->sputc(c);
}

std::streamsize LineNumberBuffer::xsputn(const char *s, std::streamsize count) {
    std::string str;
    for (int i = 0; i < count; i++) {
        str += (*(s + i));
        if (*(s + i) == '\n') {
            str.append(std::to_string(index));
            index++;
        }
    }
    return buffer->sputn(str.data(), str.size());
}
