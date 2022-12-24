#ifndef CPLUS_BUYING_GOODS_STATE_HPP
#define CPLUS_BUYING_GOODS_STATE_HPP

#include "memory"
#include "state.hpp"

class BuyingGoodsState : public State
{
public:
    BuyingGoodsState() = default;
    void handle(Game* game, int input) override;
};

#endif //CPLUS_BUYING_GOODS_STATE_HPP
