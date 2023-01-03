#include "models/ship.hpp"
#include "models/good.hpp"
#include "models/cannon.hpp"

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

int Ship::get_gold() const
{
    return _gold;
}

int Ship::get_max_goods_kg() const
{
    return _max_goods_kg;
}

int Ship::get_goods_kg_used() const
{
    return _goods_kg_used;
}

int Ship::get_max_cannons() const
{
    return _max_cannons;
}

int Ship::get_cannons_used() const
{
    return _cannons_used;
}

int Ship::get_health() const
{
    return _health;
}

int Ship::get_max_health() const
{
    return _max_health;
}

void Ship::set_gold(const int amount)
{
    _gold = amount;
}

void Ship::set_health(const int amount)
{
    _health = amount;
}

std::string Ship::get_ship_type() const {
    return _ship_type;
}

std::vector<std::shared_ptr<Good>> Ship::get_goods() const {
    return _goods;
}

std::vector<std::shared_ptr<Cannon>> Ship::get_cannons() const {
    return _cannons;
}

void Ship::set_goods(std::vector<std::shared_ptr<Good>> goods) {
    _goods = std::move(goods);
}

void Ship::set_cannons(std::vector<std::shared_ptr<Cannon>> cannons) {
    _cannons = std::move(cannons);
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
        if(g->get_good_id() == good->get_good_id())
        {
            g->set_amount(g->get_amount() + amount);
            g->set_price(g->get_price());
            _goods_kg_used += amount;
            return;
        }
    }
    auto new_good = std::make_shared<Good>(good->get_good_id(), good->get_good_name());
    new_good->set_amount(amount);
    new_good->set_price(good->get_price());
    _goods.push_back(new_good);
    _goods_kg_used += amount;
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
    _goods_kg_used -= amount;
}

std::shared_ptr<Cannon> Ship::get_cannon(int id) const {
    for(auto cannon : _cannons)
    {
        if(cannon->get_cannon_id() == id)
        {
            return cannon;
        };
    }
    return nullptr;
}

void Ship::add_cannon(const std::shared_ptr<Cannon>& cannon, int amount)
{
    for(const auto& c : _cannons)
    {
        if(c->get_cannon_id() == cannon->get_cannon_id())
        {
            c->set_amount(c->get_amount() + amount);
            c->set_price(c->get_cannon_price());
            _cannons_used += amount;
            return;
        }
    }
    auto new_cannon = std::make_shared<Cannon>(cannon->get_cannon_id(), cannon->get_cannon_name(), (cannon->get_cannon_price() /2), amount);
    _cannons.push_back(new_cannon);
    _cannons_used += amount;
}

void Ship::remove_cannon(int id, int amount) {
    for (const auto& c : _cannons)
    {
        if (c->get_cannon_id() == id)
        {
            if (c->get_amount() - amount == 0)
            {
                _cannons.erase(std::remove(_cannons.begin(), _cannons.end(), c), _cannons.end());
            }
            else
            {
                c->set_amount(c->get_amount() - amount);
            }
        }
    }
    _cannons_used -= amount;
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
        _max_cannons = value;
    }
    else if (str_column_name == "schadepunten")
    {
        _health = value;
        _max_health = value;
    }
}

void Ship::set_string_value(const char* column_name, const char* value) {
    _ship_type = std::string(value);
}

Ship::Ship(const Ship& other) {
    _ship_id = other._ship_id;
    _price = other._price;
    _max_goods_kg = other._max_goods_kg;
    _max_cannons = other._max_cannons;
    _health = other._health;
    _max_health = other._max_health;
    _gold = other._gold;
    _ship_type = other._ship_type;
    _goods_kg_used = other._goods_kg_used;
    _cannons_used = other._cannons_used;
    for (const auto& good : other._goods) {
        _goods.push_back(std::make_shared<Good>(*good));
    }
    for (const auto& cannon : other._cannons) {
        _cannons.push_back(std::make_shared<Cannon>(*cannon));
    }
}
