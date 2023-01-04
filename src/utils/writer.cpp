#include "utils/writer.hpp"

#include <filesystem>
#include "fstream"

void Writer::write_player_input(const std::string &text) {
    std::ofstream session_log("session-log.txt", std::ofstream::app);
    session_log << "[Player]: " << text << std::endl;
    session_log.close();
}

void Writer::write_game_output(const std::string &text) {
    std::ofstream session_log("session-log.txt", std::ofstream::app);
    session_log << "[Game]: " << text << std::endl;
    session_log.close();
}

void Writer::clear() {
    std::ofstream session_log("session-log.txt", std::ofstream::trunc);
    session_log.close();
}
