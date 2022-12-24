#include "states/in_town_state.hpp"

#include <iostream>

void InTownState::handle(std::shared_ptr<Game> game)
{
    std::cout << "Handling in town state" << std::endl;
}
