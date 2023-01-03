#include "states/selling_goods_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "models/good.hpp"
#include "models/harbor.hpp"
#include "ui/printer.hpp"

#include <iostream>

void SellingGoodsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            int id;
            std::cout << "Enter good id" << std::endl;
            std::cin >> id;
            if(game->get_player()->get_good(id) != nullptr)
            {
                auto good = game->get_player()->get_good(id);
                int amount;
                std::cout << "Enter amount:" << std::endl;
                std::cin >> amount;
                if(good->get_amount() >= amount && amount > 0)
                {
                    game->get_player()->remove_good(id, amount);
                    game->get_player()->set_gold(game->get_player()->get_gold() + (amount * good->get_price()));
                    auto harbor_good = game->get_current_harbor()->get_good(id);
                    harbor_good->set_amount(harbor_good->get_amount() + amount);
                    printer->print_selling_goods_menu();
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
