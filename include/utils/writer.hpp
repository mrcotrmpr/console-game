#ifndef CPLUS_WRITER_HPP
#define CPLUS_WRITER_HPP

#include "string"

class Writer {
public:
    static void write_to_file(const std::string& text);
    static void clear();
};

#endif //CPLUS_WRITER_HPP
