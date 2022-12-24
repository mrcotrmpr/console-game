#include "states/selling_goods_state.hpp"
#include "states/in_town_state.hpp"
#include "game.hpp"

#include <iostream>

void SellingGoodsState::handle(std::shared_ptr<Game> game, int input)
{
    switch (input) {
        case 0:
            game->set_state(std::make_shared<InTownState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
