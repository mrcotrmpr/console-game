#include "database/database.hpp"

#include "sqlite3.h"
#include <iostream>

std::shared_ptr<sqlite3> Database::get_connection()
{
    std::shared_ptr<sqlite3> db = nullptr;
    sqlite3* db_ptr = nullptr;
    if (sqlite3_open("huifkar.db", &db_ptr) != SQLITE_OK)
    {
        sqlite3_close(db_ptr);
        std::cerr << "Error opening database file" << std::endl;
    }
    else
    {
        db = std::shared_ptr<sqlite3>(db_ptr, sqlite3_close);
    }
    return db;
}
