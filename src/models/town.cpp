#include "models/town.hpp"

Town::Town(const int town_id, const std::string &town_name) :
    _town_id(town_id),
    _town_name(town_name) {}

int Town::get_town_id() const {
    return _town_id;
}

std::string Town::get_town_name() const {
    return _town_name;
}

void Town::set_int_value(const char* column_name, int value) {
    _town_id = value;
}

void Town::set_string_value(const char* column_name, const char* value) {
    _town_name = std::string(value);
}
