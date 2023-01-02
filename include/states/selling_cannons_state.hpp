#ifndef CPLUS_SELLING_CANNONS_STATE_HPP
#define CPLUS_SELLING_CANNONS_STATE_HPP

#include "memory"
#include "state.hpp"

class SellingCannonsState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
};

#endif //CPLUS_SELLING_CANNONS_STATE_HPP
