#include "models/game.hpp"
#include "models/harbor.hpp"
#include "models/ship.hpp"
#include "models/good.hpp"
#include "models/cannon.hpp"
#include "models/specialty.hpp"
#include "models/destination.hpp"
#include "ui/printer.hpp"
#include "states/state.hpp"
#include "states/in_harbor_state.hpp"
#include "database/database.hpp"
#include "utils/randomizer.hpp"
#include "utils/writer.hpp"

#include <utility>
#include <iostream>
#include <memory>

Game::Game():
    _state(std::make_shared<InHarborState>()),
    _printer(std::make_shared<Printer>()),
    _db(std::make_shared<Database>()),
    _random(std::make_shared<Randomizer>()),
    _writer(std::make_shared<Writer>()) {}

void Game::set_state(std::shared_ptr<State> state) {
    _state = std::move(state);
}

std::shared_ptr<Writer> Game::get_writer() const {
    return _writer;
}

std::shared_ptr<Harbor> Game::get_current_harbor() const {
    return _current_harbor;
}

std::shared_ptr<Ship> Game::get_player() const {
    return _player;
}

std::shared_ptr<Ship> Game::get_enemy() const {
    return _enemy;
}

void Game::create_enemy() {
    _enemy = _db->get_entity<Ship>("SELECT * FROM schepen WHERE id = ?", _random->get_int_between_values(1, 13));
    _enemy->set_specialty(init_specialty(_player->get_ship_id()));
    int number_of_cannons = _random->get_int_between_values(1, _enemy->get_max_cannons());

    int small = _random->get_int_between_values(0, number_of_cannons);
    int medium = _random->get_int_between_values(0, number_of_cannons - small);
    int large = number_of_cannons - (small + medium);

    std::vector<std::shared_ptr<Cannon>> cannons;
    cannons.emplace_back(std::make_unique<Cannon>(1, "small", 50, small));
    cannons.emplace_back(std::make_unique<Cannon>(2, "medium", 200, medium));
    cannons.emplace_back(std::make_unique<Cannon>(3, "large", 1000, large));

    _enemy->set_cannons(cannons);
    _enemy->set_cannons_used(number_of_cannons);
}

void Game::init_harbor(int harbor_id) {
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

    // Harbor ships
    std::vector<std::shared_ptr<Ship>> ships;
    int amount = _random->get_int_between_values(1, 5);
    for(int i = 0; i < amount; i++)
    {
        std::shared_ptr<Ship> temp = _db->get_entity<Ship>("SELECT * FROM schepen WHERE id = ?", _random->get_int_between_values(1, 13));
        temp->set_specialty(init_specialty(temp->get_ship_id()));
        ships.emplace_back(temp);
    }
    _current_harbor->set_ships(ships);

    // Harbor destinations
    auto destinations = _db->get_entities<Destination>("SELECT * from afstanden WHERE haven1_id = ?", harbor_id);
    if(destinations.empty())
    {
        destinations = _db->get_entities<Destination>("SELECT * from afstanden WHERE haven2_id = ?", harbor_id);
    }
    _current_harbor->set_destinations(destinations);
    for(const auto& destination : _current_harbor->get_destinations())
    {
        std::shared_ptr<Harbor> temp = _db->get_entity<Harbor>("SELECT * FROM havens WHERE id = ?", destination->get_to_id());
        destination->set_name(temp->get_harbor_name());
    }
}

std::string Game::init_specialty(int ship_id) const {
    std::shared_ptr<Specialty> temp = _db->get_entity<Specialty>("SELECT bijzonderheid_id FROM schepen_bijzonderheden WHERE schip_id = ?", ship_id);
    std::shared_ptr<Specialty> specialty = _db->get_entity<Specialty>("SELECT bijzonderheid FROM bijzonderheden WHERE id = ?", temp->get_id());
    return specialty->get_name().length() == 0 ? "none" : specialty->get_name();
}

void Game::_init() {
    // Setup harbor
    init_harbor(_random->get_int_between_values(1, 24));

    // Setup player
    _player = _db->get_entity<Ship>("SELECT * FROM schepen WHERE id = ?", _random->get_int_between_values(1, 13));
    _player->set_specialty(init_specialty(_player->get_ship_id()));
    _player->set_gold(_random->get_int_between_values(100000, 250000));

    // Setup printer
    _printer->set_game(shared_from_this());

    // Clear session_log
    _writer->clear();
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

void Game::set_player(const std::shared_ptr<Ship>& other) {
    _player = std::make_shared<Ship>(*other);
}
