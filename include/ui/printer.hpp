#ifndef CPLUS_PRINTER_HPP
#define CPLUS_PRINTER_HPP

#include "memory"

class Game;

class Printer
{
public:
    void set_game(std::shared_ptr<Game> game);
    void print_resources();
    void print_in_town_menu();
    void print_selling_goods_menu();
    void print_buying_goods_menu();
    void print_selling_firearms_menu();
    void print_buying_firearms_menu();
    void print_buying_wagon_menu();
    void print_repairing_wagon_menu();
    void print_picking_destination_menu();
private:
    std::shared_ptr<Game> _game;
};

#endif //CPLUS_PRINTER_HPP
