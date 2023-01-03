#ifndef CPLUS_SPECIALTY_HPP
#define CPLUS_SPECIALTY_HPP

#include "models/sqlite_model.hpp"

#include "string"

class Specialty : public SQLiteModel
{
public:
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
    [[nodiscard]] int get_id() const;
    [[nodiscard]] std::string get_name() const;
private:
    int _id;
    std::string _name;
};

#endif //CPLUS_SPECIALTY_HPP
