#include <iostream>
#include <limits>

#include "models/game.hpp"
#include "states/state.hpp"
#include "utils/writer.hpp"

int main() {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->start();

    while (game->is_running() && !game->is_won())
    {
        int input;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin >> input;
            game->get_writer()->write_player_input(std::to_string(input));
            try{
                game->handle(input);
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }
        }
    }
    exit(0);
}
