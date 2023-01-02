#ifndef CPLUS_PRINTER_HPP
#define CPLUS_PRINTER_HPP

#include "memory"

class Game;

class Printer
{
public:
    void set_game(std::shared_ptr<Game> game);
    void print_resources();
    static void print_in_harbor_menu();
    static void print_selling_goods_menu();
    void print_buying_goods_menu();
    static void print_selling_cannons_menu();
    static void print_buying_cannons_menu();
    static void print_buying_ship_menu();
    static void print_repairing_ship_menu();
    static void print_picking_destination_menu();
private:
    std::shared_ptr<Game> _game;
};

#endif //CPLUS_PRINTER_HPP
