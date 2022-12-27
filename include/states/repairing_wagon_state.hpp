#ifndef CPLUS_REPARING_WAGON_STATE_HPP
#define CPLUS_REPARING_WAGON_STATE_HPP

#include "memory"
#include "state.hpp"

class RepairingWagonState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
};

#endif //CPLUS_REPARING_WAGON_STATE_HPP
