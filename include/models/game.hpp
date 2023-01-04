#ifndef CPLUS_TESTS_GAME_HPP
#define CPLUS_TESTS_GAME_HPP

#include "string"
#include "memory"

class State;
class Printer;
class Harbor;
class Ship;
class Database;
class Randomizer;
class Writer;

class Game : public std::enable_shared_from_this<Game>
{
public:
    Game();
    void start();
    void stop();
    void handle(int input);
    void init_harbor(int harbor_id);
    [[nodiscard]] std::string init_specialty(int ship_id) const;
    [[nodiscard]] bool is_running() const;
    void set_state(std::shared_ptr<State> state);
    [[nodiscard]] std::shared_ptr<Writer> get_writer() const;
    [[nodiscard]] std::shared_ptr<Harbor> get_current_harbor() const;
    [[nodiscard]] std::shared_ptr<Ship> get_player() const;
    [[nodiscard]] std::shared_ptr<Ship> get_enemy() const;
    void set_player(const std::shared_ptr<Ship>& other);
    void create_enemy();
private:
    void _init();
    std::shared_ptr<State> _state;
    std::shared_ptr<Printer> _printer;
    std::shared_ptr<Harbor> _current_harbor;
    std::shared_ptr<Ship> _player;
    std::shared_ptr<Ship> _enemy;
    std::shared_ptr<Database> _db;
    std::shared_ptr<Randomizer> _random;
    std::shared_ptr<Writer> _writer;
    bool _running{};
};

#endif //CPLUS_TESTS_GAME_HPP
