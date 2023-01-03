#include "states/fighting_state.hpp"
#include "states/traveling_state.hpp"
#include "ui/printer.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"

#include <iostream>

void FightingState::handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input)
{
    switch (input) {
        case 1:
            printer->print_fighting_options();
            _handle_fight(game, printer);
            break;
        case 9:
            game->stop();
            break;
        default:
            std::cout << "Invalid input: " << input << std::endl;
            break;
    }
}

void FightingState::_handle_fight(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer) {
    auto specialty = game->get_player()->get_specialty();
    bool alive = true;

    while (alive && game->get_player()->get_fighting_state())
    {
        int input;
        std::cin >> input;
        switch (input) {
            case 1:
                // Shoot
                break;
            case 2:
                // Flee
                break;
            case 3:
                std::cout << "You have surrendered. You lost your cargo." << std::endl;
                std::cout << "Press any number to continue." << std::endl;
                std::cin >> input;
                game->get_player()->set_fighting_state(false);
                game->set_state(std::make_shared<TravelingState>());
                printer->print_traveling_menu();
                break;
        }
    }
}
