//
// Created by michael on 10.01.19.
//

#include "LineNumberBuffer.h"

LineNumberBuffer::LineNumberBuffer(std::streambuf *buf) : buffer(buf) {}

int LineNumberBuffer::overflow(int c) {
    if (flag){
        index++;
        std::string line_prefix = std::to_string(index) + " ";
        buffer->sputn(line_prefix.data(), line_prefix.length());
    }
    flag = (c == '\n');
    return buffer->sputc(c);
}

std::streamsize LineNumberBuffer::xsputn(const char *s, std::streamsize count) {
    std::string str;
    str.append(std::to_string(index));
    index++;
    for (int i = 0; i < count; i++) {
        str += (*(s + i));
        if (*(s + i) == '\n') {
            str.append(std::to_string(index));
            index++;
        }
    }
    return buffer->sputn(str.data(), str.size());
}
