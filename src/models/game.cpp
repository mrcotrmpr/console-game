#include "models/game.hpp"
#include "models/town.hpp"
#include "models/wagon.hpp"
#include "models/good.hpp"
#include "ui/printer.hpp"
#include "states/state.hpp"
#include "states/in_town_state.hpp"
#include "database/database.hpp"
#include "utils/randomizer.hpp"

#include <utility>
#include <iostream>

Game::Game():
    _state(std::make_shared<InTownState>()),
    _printer(std::make_shared<Printer>()),
    _db(std::make_shared<Database>()),
    _random(std::make_shared<Randomizer>()) {}

void Game::set_state(std::shared_ptr<State> state) {
    _state = std::move(state);
}

std::shared_ptr<State> Game::get_state() const {
    return _state;
}

std::shared_ptr<Printer> Game::get_printer() const {
    return _printer;
}

std::shared_ptr<Town> Game::get_current_town() const {
    return _current_town;
}

std::shared_ptr<Wagon> Game::get_player() const {
    return _player;
}

void Game::_init()
{
    // Setup town
    _current_town = _db->get_entity<Town>("SELECT * FROM steden WHERE id = ?", _random->get_int_between_values(1, 24));
    _current_town->set_goods(_db->get_entities<Good>("SELECT goed_id, min_goed, max_goed, min_prijs, max_prijs FROM steden_goederen WHERE stad_id = ?", _current_town->get_town_id()));
    for (auto good : _current_town->get_goods())
    {
        std::shared_ptr<Good> temp = _db->get_entity<Good>("SELECT * FROM goederen WHERE id = ?", good->get_good_id());
        good->set_name(temp->get_good_name());
        good->set_price(_random->get_int_between_values(good->get_min_price(), good->get_max_price()));
        good->set_amount(_random->get_int_between_values(good->get_min_amount(), good->get_max_amount()));
    }

    // Setup player
    _player = _db->get_entity<Wagon>("SELECT * FROM huifkarren WHERE id = ?", _random->get_int_between_values(1, 13));
    _player->set_florin(_random->get_int_between_values(1000, 2500));
    _printer->set_game(shared_from_this());
}

void Game::start() {
    _init();
    _running = true;
    _printer->print_in_town_menu();
}

void Game::stop() {
    std::cout << "Goodbye!" << std::endl;
    _running = false;
}

bool Game::is_running() const {
    return _running;
}

void Game::handle(int input) {
    _state->handle(shared_from_this(), _printer, input);
}
