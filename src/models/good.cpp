#include "models/good.hpp"
#include <database/database.hpp>

Good::Good(const int good_id, const std::string &good_name) :
        _good_id(good_id),
        _good_name(good_name) {}

int Good::get_good_id() const {
    return _good_id;
}

int Good::get_price() const {
    return _price;
}

int Good::get_amount() const {
    return _amount;
}

int Good::get_min_amount() const {
    return _min_amount;
}

int Good::get_max_amount() const {
    return _max_amount;
}

int Good::get_min_price() const {
    return _min_price;
}

int Good::get_max_price() const {
    return _max_price;
}

std::string Good::get_good_name() const {
    return _good_name;
}

void Good::set_price(int price) {
    _price = price;
}

void Good::set_amount(int amount) {
    _amount = amount;
}

void Good::set_name(std::string name)
{
    _good_name = name;
}

void Good::set_int_value(const char* column_name, int value) {

    std::string str_column_name = std::string(column_name);

    if (str_column_name == "id" || str_column_name == "goed_id")
    {
        _good_id = value;
    }
    else if (str_column_name == "min_goed")
    {
        _min_amount = value;
    }
    else if (str_column_name == "max_goed")
    {
        _max_amount = value;
    }
    else if (str_column_name == "min_prijs")
    {
        _min_price = value;
    }
    else if (str_column_name == "max_prijs")
    {
        _max_price = value;
    }
}

void Good::set_string_value(const char* column_name, const char* value) {
    _good_name = std::string(value);
}
