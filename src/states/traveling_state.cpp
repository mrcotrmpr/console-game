#include "states/traveling_state.hpp"
#include "states/in_harbor_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "models/destination.hpp"
#include "ui/printer.hpp"
#include "utils/randomizer.hpp"

#include <iostream>

TravelingState::TravelingState() :
    _random(std::make_shared<Randomizer>()) {}

void TravelingState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 1:
            _handle_turns(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void TravelingState::_handle_turns(const std::shared_ptr<Game> &game, const std::shared_ptr<Printer> &printer) {
    auto destination = game->get_player()->get_destination();
    int input;

    while(destination->get_turn() != destination->get_distance())
    {
        int number = _random->get_int_between_values(1,20);
        switch (number) {
            case (1,2):
                std::cout << "Nothing happened. moving on" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            case (3,4):
                std::cout << "Very light wind" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            case (5,6,7):
                std::cout << "Weak wind" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            case (8,9,10,11,12,13,14,15,16,17):
                std::cout << "Normal wind" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            case (18,19):
                std::cout << "Strong wind" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            case (20):
                std::cout << "Storm" << std::endl;
                destination->increase_turn();
                std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                break;
            default:
                break;
        }
    }
    std::cout << std::endl << "You made it! press any key to continue" << std::endl;
    std::cin >> input;

    game->init_harbor(destination->get_to_id());
    printer->print_in_harbor_menu();
    game->set_state(std::make_shared<InHarborState>());
}
