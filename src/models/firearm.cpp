#include "models/firearm.hpp"

Firearm::Firearm(const int firearm_id, const std::string &firearm_name) :
        _firearm_id(firearm_id),
        _firearm_name(firearm_name) {}

int Firearm::get_firearm_id() const {
    return _firearm_id;
}

int Firearm::get_firearm_price() const {
    return _price;
}

std::string Firearm::get_firearm_name() const {
    return _firearm_name;
}

void Firearm::set_int_value(const char* column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id")
    {
        _firearm_id = value;
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

void Firearm::set_string_value(const char* column_name, const char* value) {
    _firearm_name = std::string(value);
}
