#include "states/selling_cannons_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "models/cannon.hpp"
#include "models/harbor.hpp"
#include "ui/printer.hpp"

#include <iostream>

void SellingCannonsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            int id;
            std::cout << "Enter cannon id" << std::endl;
            std::cin >> id;
            if(game->get_player()->get_cannon(id) != nullptr)
            {
                auto cannon = game->get_player()->get_cannon(id);
                int amount;
                std::cout << "Enter amount:" << std::endl;
                std::cin >> amount;
                if(cannon->get_amount() >= amount && amount > 0)
                {
                    game->get_player()->remove_cannon(id, amount);
                    game->get_player()->set_gold(game->get_player()->get_gold() + (amount * cannon->get_cannon_price()));
                    auto harbor_cannon = game->get_current_harbor()->get_cannon(id);
                    harbor_cannon->set_amount(harbor_cannon->get_amount() + amount);
                    printer->print_selling_cannons_menu();
                }
                else
                {
                    std::cout << "Not enough goods available" << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid id" << std::endl;
            }
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
