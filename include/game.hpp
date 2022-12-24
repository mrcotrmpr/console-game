#ifndef CPLUS_TESTS_GAME_HPP
#define CPLUS_TESTS_GAME_HPP

#include "string"
#include "memory"

class State;

class Game
{
public:
    Game();
    void start();
    void stop();
    [[nodiscard]] bool is_running() const;
    void set_state(std::shared_ptr<State> state);
    [[nodiscard]] std::shared_ptr<State> get_state() const;
private:
    std::shared_ptr<State> _state;
    bool _running{};
};

#endif //CPLUS_TESTS_GAME_HPP
