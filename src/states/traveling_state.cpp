#include "states/traveling_state.hpp"
#include "states/in_harbor_state.hpp"
#include "states/fighting_state.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "models/destination.hpp"
#include "ui/printer.hpp"
#include "utils/randomizer.hpp"
#include "utils/writer.hpp"

#include <iostream>
#include <sstream>

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
            std::cout << "Invalid input" << std::endl;
            game->get_writer()->write_game_output("Invalid input");
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
                    game->get_writer()->write_game_output("The ship didn't move.");
                    _print_turn(game);
                    break;
                case (3,4):
                    if(specialty == "licht")
                    {
                        std::cout << "Normal wind. 1 turn closer." << std::endl;
                        game->get_writer()->write_game_output("Normal wind. 1 turn closer.");
                        _print_turn(game);
                        destination->increase_turn(1);
                        break;
                    }
                    else
                    {
                        std::cout << "The ship didn't move." << std::endl;
                        game->get_writer()->write_game_output("The ship didn't move.");
                        _print_turn(game);
                        break;
                    }
                case (5,6,7):
                    if(specialty == "log")
                    {
                        std::cout << "The ship didn't move." << std::endl;
                        game->get_writer()->write_game_output("The ship didn't move.");
                        _print_turn(game);
                        break;
                    }
                    else
                    {
                        std::cout << "Normal wind. 1 turn closer." << std::endl;
                        game->get_writer()->write_game_output("Normal wind. 1 turn closer.");
                        _print_turn(game);
                        destination->increase_turn(1);
                        break;
                    }
                case (8,9,10,11,12,13,14,15,16,17):
                    std::cout << "Normal wind. 1 turn closer." << std::endl;
                    game->get_writer()->write_game_output("Normal wind. 1 turn closer.");
                    _print_turn(game);
                    destination->increase_turn(1);
                    break;
                case (18,19):
                    std::cout << "Strong wind. 2 turns closer." << std::endl;
                    game->get_writer()->write_game_output("Strong wind. 2 turns closer.");
                    _print_turn(game);
                    destination->increase_turn(2);
                    break;
                case (20):
                    game->get_player()->set_health(game->get_player()->get_health() - _random->get_int_between_values(0, game->get_player()->get_health()));
                    if(game->get_player()->get_health() > 0)
                    {
                        std::cout << "You have encountered a storm and lost health." << std::endl;
                        game->get_writer()->write_game_output("You have encountered a storm and lost health.");
                        std::cout << "Remaining health: " << game->get_player()->get_health() << "/" << game->get_player()->get_max_health() << std::endl;
                        game->get_writer()->write_game_output("Remaining health: " + std::to_string(game->get_player()->get_health()) + "/" + std::to_string(game->get_player()->get_max_health()));
                        switch (_random->get_int_between_values(1, 10)) {
                            case (1, 2, 3, 4):
                                std::cout << "[STORM] Blown off course. Will take 1 turn longer." << std::endl;
                                game->get_writer()->write_game_output("[STORM] Blown off course. Will take 1 turn longer.");
                                _print_turn(game);
                                destination->increase_turn(-1);
                                break;
                            case (5, 6, 7, 8):
                                std::cout << "[STORM] Ship hasn't moved." << std::endl;
                                game->get_writer()->write_game_output("[STORM] Ship hasn't moved.");
                                _print_turn(game);
                                break;
                            case (9, 10):
                                std::cout << "[STORM] Blown in the right direction. 1 turns closer." << std::endl;
                                game->get_writer()->write_game_output("[STORM] Blown in the right direction. 1 turns closer.");
                                _print_turn(game);
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
            game->get_writer()->write_game_output("You made it! press any number to continue");
            std::cin >> input;
            game->get_writer()->write_player_input(std::to_string(input));
            game->init_harbor(destination->get_to_id());
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
        }
        else
        {
            std::cout << "You have encountered a storm and you have died." << std::endl;
            game->get_writer()->write_game_output("You have encountered a storm and you have died.");
            std::cout << "Press any number to start over" << std::endl;
            game->get_writer()->write_game_output("Press any number to start over");
            std::cin >> input;
            game->get_writer()->write_player_input(std::to_string(input));
            game->start();
            printer->print_in_harbor_menu();
            game->set_state(std::make_shared<InHarborState>());
        }
    }
}

void TravelingState::_print_turn(const std::shared_ptr<Game> &game) {
    auto destination = game->get_player()->get_destination();
    std::stringstream ss;
    ss << "Turn: " << destination->get_turn() << "/" << destination->get_distance() << std::endl;
    std::cout << ss.str();
    game->get_writer()->write_game_output(ss.str());
}
