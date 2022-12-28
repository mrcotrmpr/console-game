#include "ui/printer.hpp"
#include "models/game.hpp"
#include "models/town.hpp"
#include "models/wagon.hpp"
#include "models/good.hpp"

#include <iostream>

void Printer::set_game(std::shared_ptr<Game> game)
{
    _game = game;
}

void Printer::print_resources()
{
    print_in_town_menu();
    std::cout << std::endl << "Current town: " << _game->get_current_town()->get_town_name() << std::endl;
    std::cout << "Current wagon: " << _game->get_player()->get_wagon_type() << std::endl;
    std::cout << "Current florin: " << _game->get_player()->get_florin() << std::endl;
    std::cout << "Current health: " << _game->get_player()->get_health() << std::endl;
}

void Printer::print_in_town_menu() 
{
    system("CLS");
    std::cout << "[1] View your resources" << std::endl;
    std::cout << "[2] Buy goods" << std::endl;
    std::cout << "[3] Sell goods" << std::endl;
    std::cout << "[4] Buy firearms" << std::endl;
    std::cout << "[5] Sell firearms" << std::endl;
    std::cout << "[6] Buy new wagon" << std::endl;
    std::cout << "[7] Repair wagon" << std::endl;
    std::cout << "[8] Pick a destination" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_buying_goods_menu()
{
    system("CLS");
    std::cout << "Buying goods" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
    std::cout << std::endl << "Current goods:" << std::endl;
    for (auto good : _game->get_current_town()->get_goods())
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
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_buying_firearms_menu()
{
    system("CLS");
    std::cout << "Buying firearms" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_selling_firearms_menu()
{
    system("CLS");
    std::cout << "Selling firearms" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_buying_wagon_menu()
{
    system("CLS");
    std::cout << "Buying wagon" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_repairing_wagon_menu()
{
    system("CLS");
    std::cout << "Repairing wagon" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}

void Printer::print_picking_destination_menu()
{
    system("CLS");
    std::cout << "Picking destination" << std::endl << std::endl;
    std::cout << "[0] Return to town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}
