#ifndef CPLUS_TOWN_FACTORY_HPP
#define CPLUS_TOWN_FACTORY_HPP

#include "memory"

class Town;

class TownFactory
{
    std::shared_ptr<Town> create_town(const int town_id, const std::string& town_name);
};

#endif //CPLUS_TOWN_FACTORY_HPP
