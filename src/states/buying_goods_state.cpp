#include "states/buying_goods_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/good.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"
#include "utils/writer.hpp"

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
            game->get_writer()->write_game_output("Invalid input");
            break;
    }
}

void BuyingGoodsState::_handle_buy_goods(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer) {
    int id;
    std::cout << "Enter good id" << std::endl;
    game->get_writer()->write_game_output("Enter good id");
    std::cin >> id;
    game->get_writer()->write_player_input(std::to_string(id));

    auto good = game->get_current_harbor()->get_good(id);
    if(good != nullptr)
    {
        int amount;
        std::cout << "Enter amount:" << std::endl;
        game->get_writer()->write_game_output("Enter amount:");
        std::cin >> amount;
        game->get_writer()->write_player_input(std::to_string(amount));

        if(_validate_purchase(good, amount, game))
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
        game->get_writer()->write_game_output("Invalid id");
    }
}

bool BuyingGoodsState::_validate_purchase(const std::shared_ptr<Good>& good, int amount, const std::shared_ptr<Game>& game) {
    if(good->get_amount() >= amount && amount > 0 && (game->get_player()->get_goods_kg_used() + amount) <= game->get_player()->get_max_goods_kg())
    {
        if (game->get_player()->get_gold() >= (good->get_price() * amount))
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
        std::cout << "Not enough goods or space available" << std::endl;
        game->get_writer()->write_game_output("Not enough goods or space available");
        return false;
    }
}
