#include "models/town/town_factory.hpp"
#include "models/town/town.hpp"

std::shared_ptr<Town> TownFactory::create_town(const int town_id, const std::string &town_name){
    return std::make_shared<Town>(town_id, town_name);
};
