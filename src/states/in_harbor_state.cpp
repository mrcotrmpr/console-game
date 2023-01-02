#include "states/in_harbor_state.hpp"
#include "states/buying_goods_state.hpp"
#include "states/selling_goods_state.hpp"
#include "states/buying_cannons_state.hpp"
#include "states/selling_cannons_state.hpp"
#include "states/buying_ship_state.hpp"
#include "states/repairing_ship_state.hpp"
#include "states/picking_destination_state.hpp"

#include <iostream>
#include "models/game.hpp"
#include "ui/printer.hpp"

void InHarborState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
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
            printer->print_buying_cannons_menu();
            game->set_state(std::make_shared<BuyingCannonsState>());
            break;
        case 5:
            printer->print_selling_cannons_menu();
            game->set_state(std::make_shared<SellingCannonsState>());
            break;
        case 6:
            printer->print_buying_ship_menu();
            game->set_state(std::make_shared<BuyingShipState>());
            break;
        case 7:
            printer->print_repairing_ship_menu();
            game->set_state(std::make_shared<RepairingShipState>());
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
