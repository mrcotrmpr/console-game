#include "models/cannon.hpp"

Cannon::Cannon(const int cannon_id, const std::string &cannon_name) :
        _cannon_id(cannon_id),
        _cannon_name(cannon_name) {}

int Cannon::get_cannon_id() const {
    return _cannon_id;
}

int Cannon::get_cannon_price() const {
    return _price;
}

std::string Cannon::get_cannon_name() const {
    return _cannon_name;
}

void Cannon::set_int_value(const char* column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id")
    {
        _cannon_id = value;
    }
    else if (str_column_name == "min_aantal")
    {
        _min_amount = value;
    }
    else if (str_column_name == "max_aantal")
    {
        _max_amount = value;
    }
    else if (str_column_name == "prijs")
    {
        _price = value;
    }
    else if (str_column_name == "min_schade")
    {
        _min_damage = value;
    }
    else if (str_column_name == "max_schade")
    {
        _max_damage = value;
    }
}

void Cannon::set_string_value(const char* column_name, const char* value) {
    _cannon_name = std::string(value);
}
