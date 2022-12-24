#include "game.hpp"
#include "states/in_town_state.hpp"

#include <utility>

Game::Game():
    _state(std::make_shared<InTownState>()) {}

void Game::set_state(std::shared_ptr<State> state) {
    _state = std::move(state);
}

std::shared_ptr<State> Game::get_state() const {
    return _state;
}

void Game::start() {
    _running = true;
}

void Game::stop() {
    _running = false;
}

bool Game::is_running() const {
    return _running;
}
