#include "states/buying_goods_state.hpp"
#include "states/in_town_state.hpp"
#include "game.hpp"

#include <iostream>

void BuyingGoodsState::handle(std::shared_ptr<Game> game, int input)
{
    std::cout << "Buying goods state received: " << input << std::endl;
    switch (input) {
        case 1:
            game->set_state(std::make_shared<InTownState>());
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            game->stop();
            break;
    }}
