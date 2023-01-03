#ifndef CPLUS_TRAVELING_STATE_HPP
#define CPLUS_TRAVELING_STATE_HPP

#include "memory"
#include "state.hpp"

class Randomizer;

class TravelingState : public State
{
public:
    TravelingState();
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    void _handle_turns(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    std::shared_ptr<Randomizer> _random;
};

#endif //CPLUS_TRAVELING_STATE_HPP
