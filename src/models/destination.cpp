#include "models/destination.hpp"

std::string Destination::get_name() const {
    return _destination_name;
}

int Destination::get_from_id() const {
    return _from_destination_id;
}

int Destination::get_to_id() const {
    return _to_destination_id;
}

int Destination::get_distance() const {
    return _distance;
}

void Destination::set_name(const std::string &name) {
    _destination_name = name;
}

void Destination::set_int_value(const char *column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if(str_column_name == "afstand")
    {
        _distance = value;
    }
    if(str_column_name == "haven1_id")
    {
        _from_destination_id = value;
    }
    if(str_column_name == "haven2_id")
    {
        _to_destination_id = value;
    }
}

void Destination::set_string_value(const char *column_name, const char *value) {
    //
}
