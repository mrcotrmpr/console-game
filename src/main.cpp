#include <iostream>

#include "models/game.hpp"
#include "states/state.hpp"
#include "utils/writer.hpp"

int main() {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->start();

    while (game->is_running() && !game->is_won())
    {
        int input;
        std::cin >> input;
        game->get_writer()->write_player_input(std::to_string(input));
        game->handle(input);
    }
    exit(0);
}
