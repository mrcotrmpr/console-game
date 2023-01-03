#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "models/good.hpp"
#include "models/cannon.hpp"
#include "ui/printer.hpp"
#include "states/state.hpp"
#include "states/in_harbor_state.hpp"
#include "database/database.hpp"
#include "utils/randomizer.hpp"

#include <utility>
#include <iostream>
#include <memory>

Game::Game():
    _state(std::make_shared<InHarborState>()),
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

std::shared_ptr<Harbor> Game::get_current_harbor() const {
    return _current_harbor;
}

std::shared_ptr<Ship> Game::get_player() const {
    return _player;
}

void Game::init_harbor(int harbor_id)
{
    _current_harbor = _db->get_entity<Harbor>("SELECT * FROM havens WHERE id = ?", harbor_id);

    // Harbor goods
    _current_harbor->set_goods(_db->get_entities<Good>("SELECT goed_id, min_goed, max_goed, min_prijs, max_prijs FROM havens_goederen WHERE haven_id = ?", harbor_id));
    for (const auto& good : _current_harbor->get_goods())
    {
        std::shared_ptr<Good> temp = _db->get_entity<Good>("SELECT * FROM goederen WHERE id = ?", good->get_good_id());
        good->set_name(temp->get_good_name());
        good->set_price(_random->get_int_between_values(good->get_min_price(), good->get_max_price()));
        good->set_amount(_random->get_int_between_values(good->get_min_amount(), good->get_max_amount()));
    }

    // Harbor cannons
    std::vector<std::shared_ptr<Cannon>> cannons;
    cannons.emplace_back(std::make_unique<Cannon>(1, "small", 50, _random->get_int_between_values(0, 5)));
    cannons.emplace_back(std::make_unique<Cannon>(2, "medium", 200, _random->get_int_between_values(0, 3)));
    cannons.emplace_back(std::make_unique<Cannon>(3, "large", 1000, _random->get_int_between_values(0, 2)));
    _current_harbor->set_cannons(cannons);
}

void Game::_init()
{
    // Setup harbor
    init_harbor(_random->get_int_between_values(1, 24));

    // Setup player
    _player = _db->get_entity<Ship>("SELECT * FROM schepen WHERE id = ?", _random->get_int_between_values(1, 13));
    _player->set_gold(_random->get_int_between_values(100000, 250000));

    // Setup printer
    _printer->set_game(shared_from_this());
}

void Game::start() {
    _init();
    _running = true;
    _printer->print_in_harbor_menu();
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
