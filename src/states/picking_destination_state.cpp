#include "states/picking_destination_state.hpp"
#include "states/in_harbor_state.hpp"
#include "states/traveling_state.hpp"
#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/destination.hpp"
#include "models/ship.hpp"
#include "ui/printer.hpp"

#include <iostream>

void PickingDestinationState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 0:
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
            break;
        case 1:
            _handle_pick_destination(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void PickingDestinationState::_handle_pick_destination(const std::shared_ptr<Game> &game, const std::shared_ptr<Printer> &printer) {
    int id;
    std::cout << "Enter destination id" << std::endl;
    std::cin >> id;

    auto destination = game->get_current_harbor()->get_destination(id);
    if(destination != nullptr)
    {
        game->get_player()->set_destination(std::shared_ptr<Destination>(destination));
        printer->print_traveling_menu();
        game->set_state(std::make_shared<TravelingState>());
    }
    else
    {
        std::cout << "Invalid id" << std::endl;
    }
}
