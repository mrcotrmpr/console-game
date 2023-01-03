#include "states/traveling_state.hpp"
#include "models/game.hpp"
#include "ui/printer.hpp"

#include <iostream>

void TravelingState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}
