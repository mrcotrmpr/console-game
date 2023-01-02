#include "states/buying_goods_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/good.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"

#include <iostream>

void BuyingGoodsState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
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
            if(game->get_current_harbor()->get_good(id) != nullptr)
            {
                auto good = game->get_current_harbor()->get_good(id);
                int amount;
                std::cout << "Enter amount:" << std::endl;
                std::cin >> amount;
                if(good->get_amount() >= amount && amount > 0)
                {
                    if (game->get_player()->get_florin() >= (good->get_price() * amount))
                    {
                        game->get_player()->add_good(good, amount);
                        game->get_player()->set_florin(game->get_player()->get_florin() - good->get_price() * amount);
                        good->set_amount(good->get_amount() - amount);
                        printer->print_buying_goods_menu();
                    }
                    else
                    {
                        std::cout << "Not enough money available" << std::endl;
                    }
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
