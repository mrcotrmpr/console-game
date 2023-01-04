#include "states/fighting_state.hpp"
#include "states/traveling_state.hpp"
#include "states/in_harbor_state.hpp"
#include "ui/printer.hpp"
#include "models/game.hpp"
#include "models/ship.hpp"
#include "utils/randomizer.hpp"
#include "utils/writer.hpp"

#include <iostream>

FightingState::FightingState() :
        _random(std::make_shared<Randomizer>()) {}

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
            std::cout << "Invalid input" << std::endl;
            game->get_writer()->write_game_output("Invalid input");
            break;
    }
}

void FightingState::_handle_fight(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer) {
    auto player = game->get_player();
    auto enemy = game->get_enemy();
    bool alive = true;
    bool won = false;

    int input;
    int player_damage;
    int enemy_damage;
    while (alive && game->get_player()->get_fighting_state())
    {
        std::cin >> input;
        game->get_writer()->write_player_input(std::to_string(input));
        switch (input) {
            case 1:
                player_damage = player->get_cannons_damage();
                std::cout << "You have shot at the enemy, dealing " << player_damage << " damage." << std::endl;
                game->get_writer()->write_game_output("You have shot at the enemy, dealing " + std::to_string(player_damage) + " damage.");
                enemy->set_health(enemy->get_health() - player_damage);
                if(enemy->get_health() <= 0)
                {
                    player->set_fighting_state(false);
                    won = true;
                }
                else
                {
                    enemy_damage = game->get_enemy()->get_cannons_damage();
                    std::cout << "The enemy shot at you, dealing " << enemy_damage << " damage." << std::endl;
                    game->get_writer()->write_game_output("The enemy shot at you, dealing " + std::to_string(enemy_damage) + " damage.");
                    player->set_health(player->get_health() - enemy_damage);
                    if(player->get_health() <= 0)
                    {
                        alive = false;
                    }
                    else
                    {
                        std::cout << "Press any number to continue" << std::endl;
                        game->get_writer()->write_game_output("Press any number to continue");
                        std::cin >> input;
                        game->get_writer()->write_player_input(std::to_string(input));
                        printer->print_fighting_options();
                        break;
                    }
                }
            case 2:
                if(_calculate_flee_chance(player->get_specialty(), enemy->get_specialty()))
                {
                    std::cout << "You have fled successfully." << std::endl;
                    game->get_writer()->write_game_output("You have fled successfully.");
                    std::cout << "Press any number to continue." << std::endl;
                    game->get_writer()->write_game_output("Press any number to continue");
                    std::cin >> input;
                    game->get_writer()->write_player_input(std::to_string(input));
                    player->set_fighting_state(false);
                    game->set_state(std::make_shared<TravelingState>());
                    printer->print_traveling_menu();
                    break;
                }
                else
                {
                    enemy_damage = game->get_enemy()->get_cannons_damage();
                    std::cout << "Fleeing failed. The enemy shot at you with " << enemy_damage << " damage." << std::endl;
                    game->get_writer()->write_game_output("Fleeing failed. The enemy shot at you with " + std::to_string(enemy_damage) + " damage.");
                    player->set_health(player->get_health() - enemy_damage);
                    if(player->get_health() <= 0)
                    {
                        alive = false;
                    }
                    else
                    {
                        std::cout << "Press any number to continue" << std::endl;
                        game->get_writer()->write_game_output("Press any number to continue");
                        std::cin >> input;
                        game->get_writer()->write_player_input(std::to_string(input));
                        printer->print_fighting_options();
                    }
                }
                break;
            case 3:
                std::cout << "You have surrendered. You lost your cargo." << std::endl;
                game->get_writer()->write_game_output("You have surrendered. You lost your cargo.");
                std::cout << "Press any number to continue." << std::endl;
                game->get_writer()->write_game_output("Press any number to continue");
                std::cin >> input;
                game->get_writer()->write_player_input(std::to_string(input));
                game->get_player()->clear_cargo();
                game->get_player()->set_fighting_state(false);
                game->set_state(std::make_shared<TravelingState>());
                printer->print_traveling_menu();
                break;
            default:
                break;
        }
    }
    if(alive && won)
    {
        std::cout << std::endl << "You have won!" << std::endl;
        game->get_writer()->write_game_output("You have won!");
        std::cout << "Press any number to continue" << std::endl;
        game->get_writer()->write_game_output("Press any number to continue");
        std::cin >> input;
        game->get_writer()->write_player_input(std::to_string(input));
        game->get_player()->set_fighting_state(false);
        game->set_state(std::make_shared<TravelingState>());
        printer->print_traveling_menu();
    }
    else if(!alive)
    {
        std::cout << "You have died." << std::endl;
        game->get_writer()->write_game_output("You have died.");
        std::cout << "Press any number to start over" << std::endl;
        game->get_writer()->write_game_output("Press any number to start over");
        std::cin >> input;
        game->get_writer()->write_player_input(std::to_string(input));
        game->get_player()->set_fighting_state(false);
        game->start();
        game->set_state(std::make_shared<InHarborState>());
        printer->print_in_harbor_menu();
    }
}

bool FightingState::_calculate_flee_chance(const std::string &specialty_player, const std::string &specialty_enemy) {
    int number = _random->get_int_between_values(0, 100);
    if (specialty_player == "licht")
    {
        if (specialty_enemy == "licht")
        {
            return 50 <= number;
        }
        else if (specialty_enemy == "none")
        {
            return 60 <= number;
        }
        else return 75 <= number;
    }
    else if (specialty_player == "none")
    {
        if (specialty_enemy == "licht")
        {
            return 30 <= number;
        }
        else if (specialty_enemy == "none")
        {
            return 40 <= number;
        }
        else return 55 <= number;
    }
    else
    {
        if (specialty_enemy == "licht")
        {
            return 5 <= number;
        }
        else if (specialty_enemy == "none")
        {
            return 15 <= number;
        }
        else return 30 <= number;
    }
}
