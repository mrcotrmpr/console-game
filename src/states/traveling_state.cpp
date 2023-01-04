#include "states/traveling_state.hpp"
#include "states/in_harbor_state.hpp"
#include "states/fighting_state.hpp"
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
    auto specialty = game->get_player()->get_specialty();
    int input;
    bool alive = true;

    while(destination->get_turn() < destination->get_distance() && alive && !game->get_player()->get_fighting_state())
    {
        if(_random->get_int_between_values(1,50) == 2)
        {
            game->create_enemy();
            game->get_player()->set_fighting_state(true);
            game->set_state(std::make_shared<FightingState>());
            printer->print_fighting_menu();
        }
        else
        {
            switch (_random->get_int_between_values(1,20)) {
                case (1,2):
                    std::cout << "The ship didn't move." << std::endl;
                    std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                    break;
                case (3,4):
                    if(specialty == "licht")
                    {
                        std::cout << "Normal wind. 1 turn closer." << std::endl;
                        destination->increase_turn(1);
                        std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "The ship didn't move." << std::endl;
                        std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                        break;
                    }
                case (5,6,7):
                    if(specialty == "log")
                    {
                        std::cout << "The ship didn't move." << std::endl;
                        std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "Normal wind. 1 turn closer." << std::endl;
                        destination->increase_turn(1);
                        std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                        break;
                    }
                case (8,9,10,11,12,13,14,15,16,17):
                    std::cout << "Normal wind. 1 turn closer." << std::endl;
                    destination->increase_turn(1);
                    std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                    break;
                case (18,19):
                    std::cout << "Strong wind. 2 turns closer." << std::endl;
                    destination->increase_turn(2);
                    std::cout << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
                    break;
                case (20):
                    game->get_player()->set_health(game->get_player()->get_health() - _random->get_int_between_values(0, game->get_player()->get_health()));
                    if(game->get_player()->get_health() > 0)
                    {
                        std::cout << "You have encountered a storm and lost health." << std::endl;
                        std::cout << "Remaining health: " << game->get_player()->get_health() << "/" << game->get_player()->get_max_health() << std::endl;
                        switch (_random->get_int_between_values(1, 10)) {
                            case (1, 2, 3, 4):
                                std::cout << "[STORM] Blown off course. Will take 1 turn longer." << std::endl;
                                destination->increase_turn(-1);
                                break;
                            case (5, 6, 7, 8):
                                std::cout << "[STORM] Ship hasn't moved." << std::endl;
                                break;
                            case (9, 10):
                                std::cout << "[STORM] Blown in the right direction. 1 turns closer." << std::endl;
                                destination->increase_turn(1);
                                break;
                            default:
                                break;
                        }
                    }
                    else
                    {
                        alive = false;
                        break;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if(!game->get_player()->get_fighting_state())
    {
        if(alive)
        {
            std::cout << std::endl << "You made it! press any number to continue" << std::endl;
            std::cin >> input;

            game->init_harbor(destination->get_to_id());
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
        }
        else
        {
            std::cout << "You have encountered a storm and you have died." << std::endl;
            std::cout << "Press any number to start over" << std::endl;
            std::cin >> input;
            game->start();
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
        }
    }
}
