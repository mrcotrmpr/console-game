#include "models/ship.hpp"

Ship::Ship(const int ship_id, const std::string &ship_type) :
        _ship_id(ship_id),
        _ship_type(ship_type) {}

int Ship::get_ship_id() const {
    return _ship_id;
}

int Ship::get_ship_price() const {
    return _price;
}

int Ship::get_florin() const
{
    return _florin;
}

int Ship::get_health() const
{
    return _health;
}

std::string Ship::get_ship_type() const {
    return _ship_type;
}

void Ship::set_florin(const int amount)
{
    _florin = amount;
}

void Ship::set_int_value(const char* column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id")
    {
        _ship_id = value;
    }
    else if (str_column_name == "prijs")
    {
        _price = value;
    }
    else if (str_column_name == "laadruimte")
    {
        _max_goods_kg = value;
    }
    else if (str_column_name == "kanonnen")
    {
        _max_firearms_amount = value;
    }
    else if (str_column_name == "schadepunten")
    {
        _health = value;
    }
}

void Ship::set_string_value(const char* column_name, const char* value) {
    _ship_type = std::string(value);
}
