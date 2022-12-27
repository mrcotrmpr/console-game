#include "models/firearm/firearm.hpp"

Firearm::Firearm(const int firearm_id, const std::string &firearm_name) :
        _firearm_id(firearm_id),
        _firearm_name(firearm_name) {}

int Firearm::get_firearm_id() const {
    return _firearm_id;
}

std::string Firearm::get_firearm_name() const {
    return _firearm_name;
}
