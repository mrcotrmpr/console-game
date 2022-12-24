#ifndef CPLUS_STATE_HPP
#define CPLUS_STATE_HPP

#include "memory"

class Game;

class State
{
public:
    virtual void handle(Game* game, int input) = 0;
};

#endif //CPLUS_STATE_HPP
