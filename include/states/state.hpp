#ifndef CPLUS_STATE_HPP
#define CPLUS_STATE_HPP

#include "memory"

class Game;

class State
{
public:
    virtual void handle(std::shared_ptr<Game> game) = 0;
};

#endif //CPLUS_STATE_HPP
