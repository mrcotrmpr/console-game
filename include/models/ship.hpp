#ifndef CPLUS_SHIP_HPP
#define CPLUS_SHIP_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Ship : public SQLiteModel
{
public:
    Ship() = default;
    Ship(int ship_id, const std::string& ship_type);
    [[nodiscard]] int get_ship_id() const;
    [[nodiscard]] int get_ship_price() const; 
    [[nodiscard]] int get_florin() const; 
    [[nodiscard]] int get_health() const; 
    [[nodiscard]] std::string get_ship_type() const;
    void set_florin(int amount);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _ship_id;
    int _price;
    int _max_goods_kg;
    int _max_firearms_amount;
    int _health;
    int _florin;
    std::string _ship_type;
};

#endif //CPLUS_SHIP_HPP
