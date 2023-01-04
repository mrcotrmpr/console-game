#ifndef CPLUS_FIGHTING_STATE_HPP
#define CPLUS_FIGHTING_STATE_HPP

#include "memory"
#include "string"
#include "state.hpp"

class Randomizer;

class FightingState : public State
{
public:
    FightingState();
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    void _handle_fight(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    void _handle_shoot(const std::shared_ptr<Game>& game);
    void _handle_flee(const std::shared_ptr<Game>& game);
    void _handle_surrender(const std::shared_ptr<Game>& game);
    bool _calculate_flee_chance(const std::string& specialty_player, const std::string& specialty_enemy);
    std::shared_ptr<Randomizer> _random;

};

#endif //CPLUS_FIGHTING_STATE_HPP
