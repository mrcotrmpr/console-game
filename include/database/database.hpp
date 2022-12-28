#ifndef CPLUS_DATABASE_HPP
#define CPLUS_DATABASE_HPP

#include "memory"
#include <string>
#include <vector>
#include <iostream>

#include "sqlite3.h"

class Database
{
public:
    [[nodiscard]] static std::shared_ptr<sqlite3> get_connection();

    template<typename T>
    std::shared_ptr<T> get_entity(const std::string& sql, int id)
    {
        std::shared_ptr<T> entity = std::make_shared<T>();
        std::shared_ptr<sqlite3> db = get_connection();
        if (db != nullptr)
        {
            sqlite3_stmt* stmt;
            int rc = sqlite3_prepare_v2(db.get(), sql.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK)
            {
                std::cerr << "An error occurred" << std::endl;
            }
            else
            {
                sqlite3_bind_int(stmt, 1, id);
                rc = sqlite3_step(stmt);
                if (rc == SQLITE_ROW)
                {
                    int columnCount = sqlite3_column_count(stmt);
                    for (int i = 0; i < columnCount; i++) {
                        const char* columnName = sqlite3_column_name(stmt, i);
                        int columnType = sqlite3_column_type(stmt, i);
                        if (columnType == SQLITE_INTEGER) {
                            int value = sqlite3_column_int(stmt, i);
                            entity->set_int_value(columnName, value);
                        }
                        else if (columnType == SQLITE_TEXT) {
                            const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
                            entity->set_string_value(columnName, value);
                        }
                    }
                }

            }
            sqlite3_finalize(stmt);
        }
        else
        {
            std::cerr << "DB connection is a nullpointer" << std::endl;
        }
        return entity;
    }

    template<typename T>
    std::vector<std::shared_ptr<T>> get_entities(const std::string& sql, int id)
    {
        std::vector<std::shared_ptr<T>> entities;
        std::shared_ptr<sqlite3> db = get_connection();
        if (db != nullptr)
        {
            sqlite3_stmt* stmt;
            int rc = sqlite3_prepare_v2(db.get(), sql.c_str(), -1, &stmt, nullptr);
            if (rc != SQLITE_OK)
            {
                std::cerr << "An error occurred" << std::endl;
            }
            else
            {
                sqlite3_bind_int(stmt, 1, id);
                while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
                {
                    std::shared_ptr<T> entity = std::make_shared<T>();
                    int columnCount = sqlite3_column_count(stmt);
                    for (int i = 0; i < columnCount; i++) {
                        const char* columnName = sqlite3_column_name(stmt, i);
                        int columnType = sqlite3_column_type(stmt, i);
                        if (columnType == SQLITE_INTEGER) {
                            int value = sqlite3_column_int(stmt, i);
                            entity->set_int_value(columnName, value);
                        }
                        else if (columnType == SQLITE_TEXT) {
                            const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
                            entity->set_string_value(columnName, value);
                        }
                    }
                    entities.push_back(entity);
                }
            }
            sqlite3_finalize(stmt);
        }
        else
        {
            std::cerr << "DB connection is a nullpointer" << std::endl;
        }
        return entities;
    }
};

#endif //CPLUS_DATABASE_HPP
