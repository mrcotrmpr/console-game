#ifndef CPLUS_SELLING_CANNONS_STATE_HPP
#define CPLUS_SELLING_CANNONS_STATE_HPP

#include "memory"
#include "state.hpp"

class Cannon;

class SellingCannonsState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_sell_cannons(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    static bool _validate_sale(const std::shared_ptr<Cannon> &cannon, int amount);
};

#endif //CPLUS_SELLING_CANNONS_STATE_HPP
