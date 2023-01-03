#ifndef CPLUS_BUYING_SHIP_STATE_HPP
#define CPLUS_BUYING_SHIP_STATE_HPP

#include "memory"
#include "state.hpp"

class Ship;

class BuyingShipState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_buy_ship(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    static bool _validate_purchase(const std::shared_ptr<Ship> &player, const std::shared_ptr<Ship> &ship);
};

#endif //CPLUS_BUYING_SHIP_STATE_HPP
