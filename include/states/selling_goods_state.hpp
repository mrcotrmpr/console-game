#ifndef CPLUS_SELLING_GOODS_STATE_HPP
#define CPLUS_SELLING_GOODS_STATE_HPP

#include "memory"
#include "state.hpp"

class Good;
class Writer;

class SellingGoodsState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_sell_goods(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
    static bool _validate_sale(const std::shared_ptr<Writer>& writer, const std::shared_ptr<Good> &good, int amount);
};

#endif //CPLUS_SELLING_GOODS_STATE_HPP
