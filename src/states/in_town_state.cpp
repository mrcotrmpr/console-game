#include "states/in_town_state.hpp"
#include "states/buying_goods_state.hpp"

#include <iostream>
#include "game.hpp"

void InTownState::handle(std::shared_ptr<Game> game, int input)
{
    std::cout << "Handling in town state received: " << input << std::endl;
    switch (input) {
        case 1:
            game->set_state(std::make_shared<BuyingGoodsState>());
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            game->stop();
            break;
    }
}
