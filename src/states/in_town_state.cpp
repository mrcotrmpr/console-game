#include "states/in_town_state.hpp"
#include "states/buying_goods_state.hpp"

#include <iostream>
#include "game.hpp"
#include "ui/printer.hpp"

void InTownState::handle(std::shared_ptr<Game> game, int input)
{
    switch (input) {
        case 1:
            game->get_printer()->print_resources();
            break;
        case 2:
            std::cout << "[NEW STATE] BuyingGoodsState" << std::endl;
            game->set_state(std::make_shared<BuyingGoodsState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "[EVENT] InTownState received invalid input: " << input << std::endl;
            break;
    }
}
