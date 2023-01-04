#include "ui/printer.hpp"
#include "utils/writer.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "models/good.hpp"
#include "models/cannon.hpp"
#include "models/destination.hpp"

#include <iostream>
#include <utility>

std::shared_ptr<Game> Printer::_game = nullptr;

void Printer::set_game(std::shared_ptr<Game> game)
{
    _game = std::move(game);
}

void Printer::print_resources()
{
    std::string harbor_name = _game->get_current_harbor()->get_harbor_name();
    std::string ship_type = _game->get_player()->get_ship_type();
    std::string specialty = _game->get_player()->get_specialty();
    std::string ship_price = std::to_string(_game->get_player()->get_ship_price());
    std::string gold = std::to_string(_game->get_player()->get_gold());
    std::string health = std::to_string(_game->get_player()->get_health());
    std::string max_health = std::to_string(_game->get_player()->get_max_health());
    std::string goods_kg_used = std::to_string(_game->get_player()->get_goods_kg_used());
    std::string max_goods_kg = std::to_string(_game->get_player()->get_max_goods_kg());
    std::string cannons_used = std::to_string(_game->get_player()->get_cannons_used());
    std::string max_cannons = std::to_string(_game->get_player()->get_max_cannons());

    std::string player_info_str = "Current harbor: "
                              + harbor_name + "\n" + "\n"
                              + "Current ship: " + ship_type + "\n"
                              + "Current specialty: " + specialty + "\n"
                              + "Current ship worth: " + ship_price + "\n"
                              + "Current gold: " + gold + "\n"
                              + "Current health: " + health + "/" + max_health + "\n" + "\n"
                              + "Current cargo space: " + goods_kg_used + "/" + max_goods_kg + "\n"
                              + "Current goods: " + "\n";
    for (const auto& good : _game->get_player()->get_goods())
    {
        player_info_str += "[" + std::to_string(good->get_id()) + "] " + good->get_good_name();
        player_info_str += " -- Amount: " + std::to_string(good->get_amount()) + " kg";
        player_info_str += " -- Value: " + std::to_string(good->get_price() * good->get_amount()) + " gold" + "\n";
    }
    player_info_str += "\n" "Current cannons used: " + cannons_used + "/" + max_cannons + "\n"
                   + "Current cannons: " + "\n";
    for (const auto& cannon : _game->get_player()->get_cannons())
    {
        player_info_str += "[" + std::to_string(cannon->get_id()) + "] " + cannon->get_cannon_name();
        player_info_str += " -- Amount: " + std::to_string(cannon->get_amount());
        player_info_str += " -- Value: " + std::to_string(cannon->get_cannon_price() * cannon->get_amount()) + " gold" + "\n";
    }


    system("CLS");
    print_in_harbor_menu();
    std::cout << player_info_str << std::endl;
    _game->get_writer()->write_game_output(player_info_str);
}

void Printer::print_in_harbor_menu() 
{
    std::string menu_str = R"(
[1] View your resources
[2] Buy goods
[3] Sell goods
[4] Buy cannons
[5] Sell cannons
[6] Buy new ship
[7] Repair ship
[8] Pick a destination
[9] Quit the game
    )";
    system("CLS");
    std::cout << menu_str << std::endl;
    _game->get_writer()->write_game_output(menu_str);
}

void Printer::print_buying_goods_menu()
{
    std::string buy_goods_str = "\nBuying goods\n\n[0] Return to harbor\n[1] Buy goods\n[9] Quit the game\n\nGoods in current harbor:\n";
    for (const auto& good : _game->get_current_harbor()->get_goods()) {
        buy_goods_str += "[" + std::to_string(good->get_id()) + "] " + good->get_good_name() +
                " -- Amount: " + std::to_string(good->get_amount()) + " kg" +
                " -- Price: " + std::to_string(good->get_price()) + " gold per kg" + "\n";
    }
    system("CLS");
    std::cout << buy_goods_str << std::endl;
    _game->get_writer()->write_game_output(buy_goods_str);
}

void Printer::print_selling_goods_menu()
{
    std::string sell_goods_str = "\nSelling goods\n\n[0] Return to harbor\n[1] Sell goods\n[9] Quit the game\n\nCurrent goods:\n";
    for (const auto& good : _game->get_player()->get_goods()) {
        sell_goods_str += "[" + std::to_string(good->get_id()) + "] " + good->get_good_name() +
                         " -- Amount: " + std::to_string(good->get_amount()) + " kg" +
                         " -- Price: " + std::to_string(good->get_price() * good->get_amount()) + " gold total" + "\n";
    }
    system("CLS");
    std::cout << sell_goods_str << std::endl;
    _game->get_writer()->write_game_output(sell_goods_str);
}

void Printer::print_buying_cannons_menu()
{
    std::string buy_cannons_str = "\nBuying cannons\n\n[0] Return to harbor\n[1] Buy cannons\n[9] Quit the game\n\nCannons in current harbor:\n";
    for (const auto& cannon : _game->get_current_harbor()->get_cannons()) {
        buy_cannons_str += "[" + std::to_string(cannon->get_id()) + "] " + cannon->get_cannon_name() +
                         " -- Amount: " + std::to_string(cannon->get_amount()) +
                         " -- Price: " + std::to_string(cannon->get_cannon_price()) + " gold per cannon" + "\n";
    }
    system("CLS");
    std::cout << buy_cannons_str << std::endl;
    _game->get_writer()->write_game_output(buy_cannons_str);
}

void Printer::print_selling_cannons_menu()
{
    std::string sell_cannons_str = "\nSelling cannons\n\n[0] Return to harbor\n[1] Sell cannons\n[9] Quit the game\n\nCurrent cannons:\n";
    for (const auto& cannon : _game->get_player()->get_cannons()) {
        sell_cannons_str += "[" + std::to_string(cannon->get_id()) + "] " + cannon->get_cannon_name() +
                          " -- Amount: " + std::to_string(cannon->get_amount()) + " kg" +
                          " -- Value: " + std::to_string(cannon->get_cannon_price() * cannon->get_amount()) + " gold total" + "\n";
    }
    system("CLS");
    std::cout << sell_cannons_str << std::endl;
    _game->get_writer()->write_game_output(sell_cannons_str);
}

void Printer::print_buying_ship_menu()
{
    std::string buy_ship_str = "\nBuying ship\n\n[0] Return to harbor\n[1] Buy a new ship\n[9] Quit the game\n\nShips in current harbor:\n";
    for (const auto& ship : _game->get_current_harbor()->get_ships()) {
        buy_ship_str += "[" + std::to_string(ship->get_ship_id()) + "] " + ship->get_ship_type() +
                           " -- Price: " + std::to_string(ship->get_ship_price()) +
                           " -- Health: " + std::to_string(ship->get_max_health()) +
                           " -- Speciality: " + ship->get_specialty() +
                           " -- Max cargo space: " + std::to_string(ship->get_max_goods_kg()) +
                           " -- Max cannons: " + std::to_string(ship->get_max_cannons()) + "\n";
    }
    system("CLS");
    std::cout << buy_ship_str << std::endl;
    _game->get_writer()->write_game_output(buy_ship_str);
}

void Printer::print_repairing_ship_menu()
{
    std::string repair_ship_str = "Repairing ship\n\nCurrent health: " + std::to_string(_game->get_player()->get_health()) +
            "/" + std::to_string(_game->get_player()->get_max_health()) +
            "\n\n[0] Return to harbor\n[1] Repair ship\n[9] Quit the game\n";
    system("CLS");
    std::cout << repair_ship_str << std::endl;
    _game->get_writer()->write_game_output(repair_ship_str);
}

void Printer::print_picking_destination_menu()
{
    std::string picking_destination_str = "\nPicking destination\n\n[0] Return to harbor\n[1] Pick a destination\n[9] Quit the game\n\nAvailable destinations from the current harbor:\n";
    for (const auto& destination : _game->get_current_harbor()->get_destinations()) {
        picking_destination_str += "[" + std::to_string(destination->get_to_id()) + "] " + destination->get_name() +
                         " -- Distance: " + std::to_string(destination->get_distance()) + "\n";
    }
    system("CLS");
    std::cout << picking_destination_str << std::endl;
    _game->get_writer()->write_game_output(picking_destination_str);
}

void Printer::print_traveling_menu()
{
    std::string traveling_str = "Traveling to " + _game->get_player()->get_destination()->get_name() +
            "\n\n[1] Start traveling\n[9] Quit the game\n";
    system("CLS");
    std::cout << traveling_str << std::endl;
    _game->get_writer()->write_game_output(traveling_str);
}

void Printer::print_fighting_menu()
{
    std::string fight_menu_str = "You have encountered a fight\n[1] Start the fight\n";
    system("CLS");
    std::cout << fight_menu_str << std::endl;
    _game->get_writer()->write_game_output(fight_menu_str);
}

void Printer::print_fighting_options()
{
    std::string health = std::to_string(_game->get_player()->get_health());
    std::string max_health = std::to_string(_game->get_player()->get_max_health());
    std::string cannons_used = std::to_string(_game->get_player()->get_cannons_used());
    std::string max_cannons = std::to_string(_game->get_player()->get_max_cannons());

    std::string enemy_health = std::to_string(_game->get_enemy()->get_health());
    std::string enemy_max_health = std::to_string(_game->get_enemy()->get_max_health());
    std::string enemy_cannons_used = std::to_string(_game->get_enemy()->get_cannons_used());
    std::string enemy_max_cannons = std::to_string(_game->get_enemy()->get_max_cannons());

    std::string fight_options_str = "You are currently in a fight \n"
                                    "Current health: " + health + "/" + max_health + "\n"
                                  + "Current cannons used: " + cannons_used + "/" + max_cannons + "\n"
                                  + "Enemy health: " + enemy_health + "/" + enemy_max_health + "\n"
                                  + "Enemy cannons used: " + enemy_cannons_used + "/" + enemy_max_cannons + "\n"
                                  + "\n\n[1] Shoot\n[2] Flee\n[3] Surrender\n";
    system("CLS");
    std::cout << fight_options_str << std::endl;
    _game->get_writer()->write_game_output(fight_options_str);
}
