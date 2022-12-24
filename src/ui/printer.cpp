#include "ui/printer.hpp"

#include <iostream>

void Printer::print_resources() {
    system("CLS");
    std::cout << "Resources" << std::endl;
}

void Printer::print_in_town_menu() {
    system("CLS");
    std::cout << "[1] View your resources" << std::endl;
    std::cout << "[2] Buy goods" << std::endl;
    std::cout << "[3] Sell goods" << std::endl;
    std::cout << "[4] Buy firearms" << std::endl;
    std::cout << "[5] Sell firearms" << std::endl;
    std::cout << "[6] Buy new wagon" << std::endl;
    std::cout << "[7] Repair wagon" << std::endl;
    std::cout << "[8] Ride to a new town" << std::endl;
    std::cout << "[9] Quit the game" << std::endl;
}
