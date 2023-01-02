#include "models/ship.hpp"
#include "models/good.hpp"

#include "memory"
#include <algorithm>
#include <utility>
#include <vector>

Ship::Ship(const int ship_id, std::string ship_type) :
        _ship_id(ship_id),
        _ship_type(std::move(ship_type)) {}

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

std::vector<std::shared_ptr<Good>> Ship::get_goods() const {
    return _goods;
}

std::shared_ptr<Good> Ship::get_good(int id) const {
    for(auto good : _goods)
    {
        if(good->get_good_id() == id)
        {
            return good;
        };
    }
    return nullptr;
}

void Ship::add_good(const std::shared_ptr<Good>& good, int amount)
{
    for(const auto& g : _goods)
    {
        if(g->get_good_id() == g->get_good_id())
        {
            g->set_amount(g->get_amount() + amount);
            g->set_price(g->get_price());
            _kg_used += amount;
            return;
        }
    }
    auto new_good = std::make_shared<Good>(good->get_good_id(), good->get_good_name());
    new_good->set_amount(amount);
    new_good->set_price(good->get_price());
    _goods.push_back(new_good);
    _kg_used += amount;
}

void Ship::remove_good(int id, int amount) {
    for (const auto& g : _goods)
    {
        if (g->get_good_id() == id)
        {
            if (g->get_amount() - amount == 0)
            {
                _goods.erase(std::remove(_goods.begin(), _goods.end(), g), _goods.end());
            }
            else
            {
                g->set_amount(g->get_amount() - amount);
            }
        }
    }
    _kg_used -= amount;
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
