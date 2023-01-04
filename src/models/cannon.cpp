#include <utility>

#include "models/cannon.hpp"

Cannon::Cannon(int cannon_id, std::string cannon_name, int price, int amount) :
        _cannon_id(cannon_id),
        _cannon_name(std::move(cannon_name)),
        _price(price),
        _amount(amount)
        {}

int Cannon::get_id() const {
    return _cannon_id;
}

int Cannon::get_amount() const {
    return _amount;
}

int Cannon::get_cannon_price() const {
    return _price;
}

std::string Cannon::get_cannon_name() const {
    return _cannon_name;
}

void Cannon::set_amount(int amount) {
    _amount = amount;
}

void Cannon::set_price(int price) {
    _price = price;
}
