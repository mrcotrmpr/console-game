#ifndef CPLUS_FIGHTING_STATE_HPP
#define CPLUS_FIGHTING_STATE_HPP

#include "memory"
#include "state.hpp"

class FightingState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    void _handle_fight(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
};

#endif //CPLUS_FIGHTING_STATE_HPP
