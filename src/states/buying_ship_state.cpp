#include "states/buying_ship_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"

#include <iostream>
#include <memory>

void BuyingShipState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_buy_ship(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void BuyingShipState::_handle_buy_ship(const std::shared_ptr<Game> &game, const std::shared_ptr<Printer> &printer) {
    int id;
    std::cout << "Enter ship id" << std::endl;
    std::cin >> id;

    auto ship = game->get_current_harbor()->get_ship(id);
    if(ship != nullptr)
    {
        auto player = game->get_player();
        if(_validate_purchase(player, ship))
        {
            ship->set_gold((player->get_gold() + (player->get_ship_price() /2)) - ship->get_ship_price());
            ship->set_goods(player->get_goods());
            ship->set_cannons(player->get_cannons());
            ship->set_goods_used(player->get_goods_kg_used());
            ship->set_cannons_used(player->get_cannons_used());
            game->set_player(ship);
            printer->print_buying_ship_menu();
        }
    }
    else
    {
        std::cout << "Invalid id" << std::endl;
    }
}

bool BuyingShipState::_validate_purchase(const std::shared_ptr<Ship> &player, const std::shared_ptr<Ship> &ship) {
    if(player->get_gold() + (player->get_ship_price() /2) >= ship->get_ship_price())
    {
        return true;
    }
    else
    {
        std::cout << "Not enough money" << std::endl;
        return false;
    }
}
