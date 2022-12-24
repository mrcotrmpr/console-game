#ifndef CPLUS_IN_TOWN_STATE_HPP
#define CPLUS_IN_TOWN_STATE_HPP

#include "memory"
#include "state.hpp"

class InTownState : public State
{
public:
    InTownState() = default;
    void handle(Game* game, int input) override;
};

#endif //CPLUS_IN_TOWN_STATE_HPP
