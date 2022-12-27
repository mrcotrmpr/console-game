#ifndef CPLUS_STATE_HPP
#define CPLUS_STATE_HPP

#include "memory"

class Game;
class Printer;

class State
{
public:
    virtual void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) = 0;
};

#endif //CPLUS_STATE_HPP
