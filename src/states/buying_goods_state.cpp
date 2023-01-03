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
            _handle_buy_goods(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void BuyingGoodsState::_handle_buy_goods(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer) {
    int id;
    std::cout << "Enter good id" << std::endl;
    std::cin >> id;

    auto good = game->get_current_harbor()->get_good(id);
    if(good != nullptr)
    {
        int amount;
        std::cout << "Enter amount:" << std::endl;
        std::cin >> amount;

        if(_validate_purchase(good, amount, game->get_player()))
        {
            game->get_player()->add_good(good, amount);
            game->get_player()->set_gold(game->get_player()->get_gold() - (good->get_price() * amount));
            good->set_amount(good->get_amount() - amount);
            printer->print_buying_goods_menu();
        }
    }
    else
    {
        std::cout << "Invalid id" << std::endl;
    }
}

bool BuyingGoodsState::_validate_purchase(const std::shared_ptr<Good>& good, int amount, const std::shared_ptr<Ship>& player) {
    if(good->get_amount() >= amount && amount > 0 && (player->get_goods_kg_used() + amount) <= player->get_max_goods_kg())
    {
        if (player->get_gold() >= (good->get_price() * amount))
        {
            return true;
        }
        else
        {
            std::cout << "Not enough gold available" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Not enough goods or space available" << std::endl;
        return false;
    }
}
