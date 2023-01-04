#include "utils/writer.hpp"

#include <filesystem>
#include "fstream"

void Writer::write_to_file(const std::string &text) {
    std::ofstream session_log("session-log.txt", std::ofstream::app);
    session_log << text << std::endl;
    session_log.close();
}

void Writer::clear() {
    std::ofstream session_log("session-log.txt", std::ofstream::trunc);
    session_log.close();
}
