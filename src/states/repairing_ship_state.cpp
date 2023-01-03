#include "states/repairing_ship_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"

#include <iostream>

void RepairingShipState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_repair_ship(game->get_player(), printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void RepairingShipState::_handle_repair_ship(const std::shared_ptr<Ship> &player, const std::shared_ptr<Printer> &printer) {
    int gold;
    std::cout << "For how many gold would you like to repair? (1 gold = 10 hp)" << std::endl;
    std::cin >> gold;
    if(_validate_repair(gold, player))
    {
        player->set_gold(player->get_gold() - gold);
        player->set_health(player->get_health() + (gold * 10));
        printer->print_repairing_ship_menu();
    }
}

bool RepairingShipState::_validate_repair(int amount, const std::shared_ptr<Ship> &player) {
    if(player->get_health() + (amount * 10) > player->get_max_health())
    {
        std::cout << "Cannot get more hp than your maximum amount" << std::endl;
        return false;
    }
    else
    {
        if(player->get_gold() - amount < 0)
        {
            std::cout << "Not enough gold" << std::endl;
            return false;
        }
        else
        {
            return true;
        }
    }
}
