#include "states/in_town_state.hpp"
#include "states/buying_goods_state.hpp"
#include "states/selling_goods_state.hpp"
#include "states/buying_firearms_state.hpp"
#include "states/selling_firearms_state.hpp"
#include "states/buying_wagon_state.hpp"
#include "states/repairing_wagon_state.hpp"
#include "states/picking_destination_state.hpp"

#include <iostream>
#include "models/game.hpp"
#include "ui/printer.hpp"

void InTownState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 1:
            printer->print_resources();
            break;
        case 2:
            printer->print_buying_goods_menu();
            game->set_state(std::make_shared<BuyingGoodsState>());
            break;
        case 3:
            printer->print_selling_goods_menu();
            game->set_state(std::make_shared<SellingGoodsState>());
            break;
        case 4:
            printer->print_buying_firearms_menu();
            game->set_state(std::make_shared<BuyingFirearmsState>());
            break;
        case 5:
            printer->print_selling_firearms_menu();
            game->set_state(std::make_shared<SellingFirearmsState>());
            break;
        case 6:
            printer->print_buying_wagon_menu();
            game->set_state(std::make_shared<BuyingWagonState>());
            break;
        case 7:
            printer->print_repairing_wagon_menu();
            game->set_state(std::make_shared<RepairingWagonState>());
            break;
        case 8:
            printer->print_picking_destination_menu();
            game->set_state(std::make_shared<PickingDestinationState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
