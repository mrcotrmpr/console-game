#ifndef CPLUS_BUYING_CANNONS_STATE_HPP
#define CPLUS_BUYING_CANNONS_STATE_HPP

#include "memory"
#include "state.hpp"

class Cannon;

class BuyingCannonsState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_buy_cannons(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    static bool _validate_purchase(const std::shared_ptr<Cannon> &cannon, int amount, const std::shared_ptr<Game> &game);
};

#endif //CPLUS_BUYING_CANNONS_STATE_HPP
