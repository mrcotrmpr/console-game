#ifndef CPLUS_DATABASE_HPP
#define CPLUS_DATABASE_HPP

#include "memory"

class sqlite;

class Database
{
public:
    [[nodiscard]] std::shared_ptr<sqlite> get_connection() const;
    template<typename T>
    T get_entity(std::shared_ptr<sqlite>, const std::string sql);
};

#endif //CPLUS_DATABASE_HPP
