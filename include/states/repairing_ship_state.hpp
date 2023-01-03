#ifndef CPLUS_REPARING_SHIP_STATE_HPP
#define CPLUS_REPARING_SHIP_STATE_HPP

#include "memory"
#include "state.hpp"

class Ship;

class RepairingShipState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_repair_ship(const std::shared_ptr<Ship> &player, const std::shared_ptr<Printer>& printer);
    static bool _validate_repair(int amount, const std::shared_ptr<Ship> &player);
};

#endif //CPLUS_REPARING_SHIP_STATE_HPP
