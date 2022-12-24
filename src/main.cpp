#include <iostream>

#include "game.hpp"
#include "states/state.hpp"

int main() {
    Game game;
    game.start();

    while (game.is_running())
    {
        int input;
        std::cin >> input;
        game.handle(input);
    }
    exit(0);
}
