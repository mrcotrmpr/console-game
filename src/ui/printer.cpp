#include "ui/printer.hpp"

#include <iostream>

void Printer::print_resources() 
{
    std::cout << std::endl << "Resources:" << std::endl;
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
