#include "states/selling_cannons_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "models/cannon.hpp"
#include "models/harbor.hpp"
#include "ui/printer.hpp"
#include "utils/writer.hpp"

#include <iostream>

void SellingCannonsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_sell_cannons(game, printer);
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

void SellingCannonsState::_handle_sell_cannons(const std::shared_ptr<Game> &game, const std::shared_ptr<Printer> &printer) {
    int id;
    std::cout << "Enter cannon id" << std::endl;
    game->get_writer()->write_game_output("Enter cannon id");
    std::cin >> id;
    game->get_writer()->write_player_input(std::to_string(id));

    auto cannon = game->get_player()->get_element(id, game->get_player()->get_cannons());
    if(cannon != nullptr)
    {
        int amount;
        std::cout << "Enter amount:" << std::endl;
        game->get_writer()->write_game_output("Enter amount");
        std::cin >> amount;
        game->get_writer()->write_player_input(std::to_string(amount));

        if(_validate_sale(game->get_writer(), cannon, amount))
        {
            game->get_player()->remove_cannon(id, amount);
            game->get_player()->set_gold(game->get_player()->get_gold() + (amount * cannon->get_cannon_price()));
            auto harbor_cannon = game->get_current_harbor()->get_cannon(id);
            harbor_cannon->set_amount(harbor_cannon->get_amount() + amount);
            printer->print_selling_cannons_menu();
        }
    }
    else
    {
        std::cout << "Invalid id" << std::endl;
        game->get_writer()->write_game_output("Invalid id");
    }
}

bool SellingCannonsState::_validate_sale(const std::shared_ptr<Writer>& writer, const std::shared_ptr<Cannon> &cannon, int amount) {
    if(cannon->get_amount() >= amount && amount > 0)
    {
        return true;
    }
    else
    {
        std::cout << "Not enough cannons available" << std::endl;
        writer->write_game_output("Not enough cannons available");
        return false;
    }
}
