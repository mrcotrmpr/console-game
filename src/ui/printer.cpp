#include "ui/printer.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "models/good.hpp"

#include <iostream>
#include <utility>

std::shared_ptr<Game> Printer::_game = nullptr;

void Printer::set_game(std::shared_ptr<Game> game)
{
    _game = std::move(game);
}

void Printer::print_resources()
{
    print_in_harbor_menu();
    std::cout << std::endl << "Current harbor: " << _game->get_current_harbor()->get_harbor_name() << std::endl;
    std::cout << "Current ship: " << _game->get_player()->get_ship_type() << std::endl;
    std::cout << "Current florin: " << _game->get_player()->get_florin() << std::endl;
    std::cout << "Current health: " << _game->get_player()->get_health() << std::endl << std::endl;
    std::cout << "Current cargo space: " << _game->get_player()->get_kg_used() << "/" << _game->get_player()->get_max_kg() << std::endl << std::endl;
    std::cout << "Current goods: " << std::endl;
    for (const auto& good : _game->get_player()->get_goods())
    {
        std::cout << "[" << good->get_good_id() << "] " << good->get_good_name();
        std::cout << " -- Amount: " << good->get_amount() << " kg";
        std::cout << " -- Price: " << good->get_price() << " florin" << std::endl;
    }
}

void Printer::print_in_harbor_menu() 
{
    system("CLS");
    std::cout << "[1] View your resources" << std::endl;
    std::cout << "[2] Buy goods" << std::endl;
    std::cout << "[3] Sell goods" << std::endl;
    std::cout << "[4] Buy cannons" << std::endl;
    std::cout << "[5] Sell cannons" << std::endl;
    std::cout << "[6] Buy new ship" << std::endl;
    std::cout << "[7] Repair ship" << std::endl;
    std::cout << "[8] Pick a destination" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_buying_goods_menu()
{
    system("CLS");
    std::cout << "Buying goods" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[1] Buy goods" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
    std::cout << std::endl << "Goods in current harbor:" << std::endl;
    for (const auto& good : _game->get_current_harbor()->get_goods())
    {
        std::cout << "[" << good->get_good_id() << "] " << good->get_good_name();
        std::cout << " -- Amount: " << good->get_amount() << " kg";
        std::cout << " -- Price: " << good->get_price() << " florin" << std::endl;
    }
}

void Printer::print_selling_goods_menu()
{
    system("CLS");
    std::cout << "Selling goods" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
    std::cout << std::endl << "Current goods:" << std::endl;
    for (const auto& good : _game->get_player()->get_goods())
    {
        std::cout << "[" << good->get_good_id() << "] " << good->get_good_name();
        std::cout << " -- Amount: " << good->get_amount() << " kg";
        std::cout << " -- Price: " << good->get_price() * good->get_amount() << " florin" << std::endl;
    }
}

void Printer::print_buying_cannons_menu()
{
    system("CLS");
    std::cout << "Buying cannons" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_selling_cannons_menu()
{
    system("CLS");
    std::cout << "Selling cannons" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_buying_ship_menu()
{
    system("CLS");
    std::cout << "Buying ship" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_repairing_ship_menu()
{
    system("CLS");
    std::cout << "Repairing ship" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_picking_destination_menu()
{
    system("CLS");
    std::cout << "Picking destination" << std::endl << std::endl;
    std::cout << "[0] Return to harbor" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}
