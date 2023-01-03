#ifndef CPLUS_TRAVELING_STATE_HPP
#define CPLUS_TRAVELING_STATE_HPP

#include "memory"
#include "state.hpp"

class TravelingState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
};

#endif //CPLUS_TRAVELING_STATE_HPP
