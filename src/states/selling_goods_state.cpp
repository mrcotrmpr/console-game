#include "states/selling_goods_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "ui/printer.hpp"

#include <iostream>

void SellingGoodsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
