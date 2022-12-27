#ifndef CPLUS_DATABASE_HPP
#define CPLUS_DATABASE_HPP

#include "memory"
#include <string>

class sqlite3;

class Database
{
public:
    [[nodiscard]] static std::shared_ptr<sqlite3> get_connection();
    template<typename T>
    T get_entity(const std::string& sql);
};

#endif //CPLUS_DATABASE_HPP
