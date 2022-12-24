#include <iostream>

#include "game.hpp"
#include "states/state.hpp"

int main() {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->start();

    while (game->is_running())
    {
        int input;
        std::cin >> input;
        game->handle(input);
    }
    exit(0);
}
