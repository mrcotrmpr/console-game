#include "states/in_harbor_state.hpp"
#include "states/buying_goods_state.hpp"
#include "states/selling_goods_state.hpp"
#include "states/buying_cannons_state.hpp"
#include "states/selling_cannons_state.hpp"
#include "states/buying_ship_state.hpp"
#include "states/repairing_ship_state.hpp"
#include "states/picking_destination_state.hpp"
#include "models/game.hpp"
#include "ui/printer.hpp"
#include "utils/writer.hpp"

#include <iostream>


void InHarborState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 1:
            printer->print_resources();
            game->get_writer()->write_to_file("[1] Printing resources");
            break;
        case 2:
            printer->print_buying_goods_menu();
            game->set_state(std::make_shared<BuyingGoodsState>());
            game->get_writer()->write_to_file("[2] Buying goods");
            break;
        case 3:
            printer->print_selling_goods_menu();
            game->set_state(std::make_shared<SellingGoodsState>());
            game->get_writer()->write_to_file("[3] Selling goods");
            break;
        case 4:
            printer->print_buying_cannons_menu();
            game->set_state(std::make_shared<BuyingCannonsState>());
            game->get_writer()->write_to_file("[4] Buying cannons");
            break;
        case 5:
            printer->print_selling_cannons_menu();
            game->set_state(std::make_shared<SellingCannonsState>());
            game->get_writer()->write_to_file("[5] Selling cannons");
            break;
        case 6:
            printer->print_buying_ship_menu();
            game->set_state(std::make_shared<BuyingShipState>());
            game->get_writer()->write_to_file("[6] Buying ship");
            break;
        case 7:
            printer->print_repairing_ship_menu();
            game->set_state(std::make_shared<RepairingShipState>());
            game->get_writer()->write_to_file("[7] Repairing ship");
            break;
        case 8:
            printer->print_picking_destination_menu();
            game->set_state(std::make_shared<PickingDestinationState>());
            game->get_writer()->write_to_file("[8] Picking destination");
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
