#ifndef CPLUS_WRITER_HPP
#define CPLUS_WRITER_HPP

#include "string"

class Writer {
public:
    static void write_player_input(const std::string& text);
    static void write_game_output(const std::string& text);
    static void clear();
};

#endif //CPLUS_WRITER_HPP
