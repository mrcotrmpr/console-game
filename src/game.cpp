#include "game.hpp"
#include "ui/printer.hpp"
#include "states/state.hpp"
#include "states/in_town_state.hpp"

#include <utility>
#include <iostream>

Game::Game():
    _state(std::make_shared<InTownState>()),
    _printer(std::make_shared<Printer>())
    {}

void Game::set_state(std::shared_ptr<State> state) {
    _state = std::move(state);
}

std::shared_ptr<State> Game::get_state() const {
    return _state;
}

std::shared_ptr<Printer> Game::get_printer() const {
    return _printer;
}

void Game::start() {
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
