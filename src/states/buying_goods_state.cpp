#include "states/buying_goods_state.hpp"
#include "states/in_town_state.hpp"
#include "game.hpp"

#include <iostream>

void BuyingGoodsState::handle(std::shared_ptr<Game> game, int input)
{
    switch (input) {
        case 1:
            std::cout << "[NEW STATE] InTownState" << std::endl;
            game->set_state(std::make_shared<InTownState>());
            break;
        default:
            std::cout << "[EVENT] BuyingGoodsState received invalid input: " << input << std::endl;
            break;
    }
}
