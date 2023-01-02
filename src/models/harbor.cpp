#include <utility>

#include "models/harbor.hpp"
#include "models/good.hpp"

Harbor::Harbor(const int harbor_id, std::string harbor_name) :
    _harbor_id(harbor_id),
    _harbor_name(std::move(harbor_name)) {}

int Harbor::get_harbor_id() const {
    return _harbor_id;
}

std::string Harbor::get_harbor_name() const {
    return _harbor_name;
}

std::vector<std::shared_ptr<Good>> Harbor::get_goods() const
{
    return _goods;
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

void Harbor::set_goods(const std::vector<std::shared_ptr<Good>>& goods)
{
    _goods = goods;
}

void Harbor::set_int_value(const char* column_name, int value) {
    _harbor_id = value;
}

void Harbor::set_string_value(const char* column_name, const char* value) {
    _harbor_name = std::string(value);
}
