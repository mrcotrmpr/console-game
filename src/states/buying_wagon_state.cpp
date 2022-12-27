#include "states/buying_wagon_state.hpp"
#include "states/in_town_state.hpp"
#include "game.hpp"
#include "ui/printer.hpp"

#include <iostream>

void BuyingWagonState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_town_menu();
            game->set_state(std::make_shared<InTownState>());
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
