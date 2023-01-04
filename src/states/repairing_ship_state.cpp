#include "states/repairing_ship_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"
#include "utils/writer.hpp"

#include <iostream>

void RepairingShipState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_repair_ship(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            game->get_writer()->write_game_output("Invalid input");
            break;
    }
}

void RepairingShipState::_handle_repair_ship(const std::shared_ptr<Game> &game, const std::shared_ptr<Printer> &printer) {
    int gold;
    std::cout << "For how many gold would you like to repair? (1 gold = 10 hp)" << std::endl;
    game->get_writer()->write_game_output("For how many gold would you like to repair? (1 gold = 10 hp)");
    std::cin >> gold;
    game->get_writer()->write_player_input(std::to_string(gold));

    if(_validate_repair(gold, game))
    {
        game->get_player()->set_gold(game->get_player()->get_gold() - gold);
        game->get_player()->set_health(game->get_player()->get_health() + (gold * 10));
        printer->print_repairing_ship_menu();
    }
}

bool RepairingShipState::_validate_repair(int amount, const std::shared_ptr<Game> &game) {
    if(game->get_player()->get_health() + (amount * 10) > game->get_player()->get_max_health())
    {
        std::cout << "Cannot get more hp than your maximum amount" << std::endl;
        game->get_writer()->write_game_output("Cannot get more hp than your maximum amount");
        return false;
    }
    else
    {
        if(game->get_player()->get_gold() - amount < 0)
        {
            std::cout << "Not enough gold" << std::endl;
            game->get_writer()->write_game_output("Not enough gold");
            return false;
        }
        else
        {
            return true;
        }
    }
}
