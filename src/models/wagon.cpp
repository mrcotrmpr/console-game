#include "models/wagon.hpp"

Wagon::Wagon(const int wagon_id, const std::string &wagon_type) :
        _wagon_id(wagon_id),
        _wagon_type(wagon_type) {}

int Wagon::get_wagon_id() const {
    return _wagon_id;
}

int Wagon::get_wagon_price() const {
    return _price;
}

std::string Wagon::get_wagon_type() const {
    return _wagon_type;
}

void Wagon::set_int_value(const char* column_name, int value) {
    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id")
    {
        _wagon_id = value;
    }
    else if (str_column_name == "prijs")
    {
        _price = value;
    }
    else if (str_column_name == "laadruimte")
    {
        _max_goods_kg = value;
    }
    else if (str_column_name == "vuurwapens")
    {
        _max_firearms_amount = value;
    }
    else if (str_column_name == "schadepunten")
    {
        _health = value;
    }
}

void Wagon::set_string_value(const char* column_name, const char* value) {
    _wagon_type = std::string(value);
}
