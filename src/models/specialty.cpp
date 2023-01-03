#include "models/specialty.hpp"

std::string Specialty::get_name() const {
    return _name;
}

int Specialty::get_id() const {
    return _id;
}

void Specialty::set_int_value(const char *column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id" || str_column_name == "bijzonderheid_id")
    {
        _id = value;
    }
}

void Specialty::set_string_value(const char *column_name, const char *value) {
    _name = value;
}
