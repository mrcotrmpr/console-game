#include "models/good/good.hpp"

Good::Good(const int good_id, const std::string &good_name) :
        _good_id(good_id),
        _good_name(good_name) {}

int Good::get_good_id() const {
    return _good_id;
}

std::string Good::get_good_name() const {
    return _good_name;
}
