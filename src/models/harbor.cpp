#include <utility>

#include "models/harbor.hpp"
#include "models/good.hpp"
#include "models/cannon.hpp"
#include "models/ship.hpp"
#include "models/destination.hpp"

Harbor::Harbor(const int harbor_id, std::string harbor_name) :
    _harbor_id(harbor_id),
    _harbor_name(std::move(harbor_name)) {}

int Harbor::get_harbor_id() const {
    return _harbor_id;
}

std::string Harbor::get_harbor_name() const {
    return _harbor_name;
}

std::vector<std::shared_ptr<Good>> Harbor::get_goods() const {
    return _goods;
}

std::vector<std::shared_ptr<Cannon>> Harbor::get_cannons() const {
    return _cannons;
}

std::vector<std::shared_ptr<Ship>> Harbor::get_ships() const {
    return _ships;
}

std::vector<std::shared_ptr<Destination>> Harbor::get_destinations() const {
    return _destinations;
}

std::shared_ptr<Good> Harbor::get_good(int id) const {
    for(auto good : _goods)
    {
        if(good->get_good_id() == id)
        {
            return good;
        };
    }
    return nullptr;
}

std::shared_ptr<Cannon> Harbor::get_cannon(int id) const {
    for(const auto& cannon : _cannons)
    {
        if(cannon->get_cannon_id() == id)
        {
            return cannon;
        };
    }
    return nullptr;
}

std::shared_ptr<Ship> Harbor::get_ship(int id) const {
    for(const auto& ship : _ships)
    {
        if(ship->get_ship_id() == id)
        {
            return ship;
        };
    }
    return nullptr;
}

std::shared_ptr<Destination> Harbor::get_destination(int id) const {
    for(const auto& destination : _destinations)
    {
        if(destination->get_to_id() == id)
        {
            return destination;
        };
    }
    return nullptr;
}

void Harbor::set_goods(const std::vector<std::shared_ptr<Good>>& goods) {
    _goods = goods;
}

void Harbor::set_cannons(const std::vector<std::shared_ptr<Cannon>>& cannons) {
    _cannons = cannons;
}

void Harbor::set_ships(const std::vector<std::shared_ptr<Ship>>& ships) {
    _ships = ships;
}

void Harbor::set_destinations(const std::vector<std::shared_ptr<Destination>>& destinations) {
    _destinations = destinations;
}

void Harbor::set_int_value(const char* column_name, int value) {
    _harbor_id = value;
}

void Harbor::set_string_value(const char* column_name, const char* value) {
    _harbor_name = std::string(value);
}
