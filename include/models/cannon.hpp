#ifndef CPLUS_CANNON_HPP
#define CPLUS_CANNON_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Cannon
{
public:
    Cannon() = default;
    Cannon(int cannon_id, std::string cannon_name, int price, int amount);
    [[nodiscard]] int get_id() const;
    [[nodiscard]] int get_cannon_price() const;
    [[nodiscard]] int get_amount() const;
    [[nodiscard]] std::string get_cannon_name() const;
    void set_amount(int amount);
    void set_price(int price);
private:
    int _cannon_id{};
    std::string _cannon_name;
    int _price{};
    int _amount{};
};

#endif //CPLUS_CANNON_HPP
