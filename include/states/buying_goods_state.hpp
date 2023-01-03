#ifndef CPLUS_BUYING_GOODS_STATE_HPP
#define CPLUS_BUYING_GOODS_STATE_HPP

#include "memory"
#include "state.hpp"

class Good;
class Ship;

class BuyingGoodsState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_buy_goods(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    static bool _validate_purchase(const std::shared_ptr<Good> &good, int amount, const std::shared_ptr<Ship> &player);
};

#endif //CPLUS_BUYING_GOODS_STATE_HPP
