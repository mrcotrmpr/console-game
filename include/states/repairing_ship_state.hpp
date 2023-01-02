#ifndef CPLUS_REPARING_SHIP_STATE_HPP
#define CPLUS_REPARING_SHIP_STATE_HPP

#include "memory"
#include "state.hpp"

class RepairingShipState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
};

#endif //CPLUS_REPARING_SHIP_STATE_HPP
