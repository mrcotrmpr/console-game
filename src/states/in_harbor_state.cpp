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
#include <sstream>


void InHarborState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 1:
            game->get_writer()->write_player_input("[1] Printing resources");
            printer->print_resources();
            break;
        case 2:
            game->get_writer()->write_player_input("[2] Buying goods");
            printer->print_buying_goods_menu();
            game->set_state(std::make_shared<BuyingGoodsState>());
            break;
        case 3:
            game->get_writer()->write_player_input("[3] Selling goods");
            printer->print_selling_goods_menu();
            game->set_state(std::make_shared<SellingGoodsState>());
            break;
        case 4:
            game->get_writer()->write_player_input("[4] Buying cannons");
            printer->print_buying_cannons_menu();
            game->set_state(std::make_shared<BuyingCannonsState>());
            break;
        case 5:
            game->get_writer()->write_player_input("[5] Selling cannons");
            printer->print_selling_cannons_menu();
            game->set_state(std::make_shared<SellingCannonsState>());
            break;
        case 6:
            game->get_writer()->write_player_input("[6] Buying ship");
            printer->print_buying_ship_menu();
            game->set_state(std::make_shared<BuyingShipState>());
            break;
        case 7:
            game->get_writer()->write_player_input("[7] Repairing ship");
            printer->print_repairing_ship_menu();
            game->set_state(std::make_shared<RepairingShipState>());
            break;
        case 8:
            game->get_writer()->write_player_input("[8] Picking destination");
            printer->print_picking_destination_menu();
            game->set_state(std::make_shared<PickingDestinationState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            std::stringstream ss;
            ss << "Invalid input: " << input;
            game->get_writer()->write_game_output(ss.str());
            break;
    }
}
