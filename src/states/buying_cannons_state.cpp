#include "states/buying_cannons_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "models/cannon.hpp"
#include "ui/printer.hpp"
#include "utils/writer.hpp"

#include <iostream>

void BuyingCannonsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_buy_cannons(game, printer);
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

void BuyingCannonsState::_handle_buy_cannons(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer) {
    int id;
    std::cout << "Enter cannon id" << std::endl;
    game->get_writer()->write_game_output("Enter cannon id");
    std::cin >> id;
    game->get_writer()->write_player_input(std::to_string(id));

    auto cannon = game->get_current_harbor()->get_cannon(id);
    if(cannon != nullptr)
    {
        int amount;
        std::cout << "Enter amount:" << std::endl;
        game->get_writer()->write_game_output("Enter amount:");
        std::cin >> amount;
        game->get_writer()->write_player_input(std::to_string(amount));

        if(_validate_purchase(cannon, amount, game))
        {
            game->get_player()->add_cannon(cannon, amount);
            game->get_player()->set_gold(game->get_player()->get_gold() - (cannon->get_cannon_price() * amount));
            cannon->set_amount(cannon->get_amount() - amount);
            printer->print_buying_cannons_menu();
        }
    }
    else
    {
        std::cout << "Invalid id" << std::endl;
        game->get_writer()->write_game_output("Invalid id");
    }
}

bool BuyingCannonsState::_validate_purchase(const std::shared_ptr<Cannon>& cannon, int amount, const std::shared_ptr<Game>& game) {
    if(cannon->get_amount() >= amount && amount > 0 && (game->get_player()->get_cannons_used() + amount) <= game->get_player()->get_max_cannons())
    {
        if (game->get_player()->get_gold() >= (cannon->get_cannon_price() * amount))
        {
            return true;
        }
        else
        {
            std::cout << "Not enough gold available" << std::endl;
            game->get_writer()->write_game_output("Not enough gold available");
            return false;
        }
    }
    else
    {
        std::cout << "Not enough cannons or space available" << std::endl;
        game->get_writer()->write_game_output("Not enough cannons or space available");
        return false;
    }
}
