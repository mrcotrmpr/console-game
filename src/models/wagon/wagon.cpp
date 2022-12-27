#include "models/wagon/wagon.hpp"

Wagon::Wagon(const int wagon_id, const std::string &wagon_type) :
        _wagon_id(wagon_id),
        _wagon_type(wagon_type) {}

int Wagon::get_wagon_id() const {
    return _wagon_id;
}

std::string Wagon::get_wagon_type() const {
    return _wagon_type;
}
