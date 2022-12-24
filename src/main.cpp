#include "game.hpp"
#include "states/state.hpp"

int main() {
    Game game;
    game.start();

    while (game.is_running())
    {
        game.get_state()->handle(std::make_shared<Game>(game));
        game.stop();
    }
    exit(0);
}
