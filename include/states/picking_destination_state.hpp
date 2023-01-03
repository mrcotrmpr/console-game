#ifndef CPLUS_PICKING_DESTINATION_STATE_HPP
#define CPLUS_PICKING_DESTINATION_STATE_HPP

#include "memory"
#include "state.hpp"

class PickingDestinationState : public State
{
public:
    void handle(std::shared_ptr<Game> game, std::shared_ptr<Printer> printer, int input) override;
private:
    static void _handle_pick_destination(const std::shared_ptr<Game>& game, const std::shared_ptr<Printer>& printer);
};

#endif //CPLUS_PICKING_DESTINATION_STATE_HPP
