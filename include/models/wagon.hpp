#ifndef CPLUS_WAGON_HPP
#define CPLUS_WAGON_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Wagon : public SQLiteModel
{
public:
    Wagon() = default;
    Wagon(const int wagon_id, const std::string& wagon_type);
    [[nodiscard]] int get_wagon_id() const;
    [[nodiscard]] int get_wagon_price() const; 
    [[nodiscard]] int get_florin() const; 
    [[nodiscard]] int get_health() const; 
    [[nodiscard]] std::string get_wagon_type() const;
    void set_florin(const int amount);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _wagon_id;
    int _price;
    int _max_goods_kg;
    int _max_firearms_amount;
    int _health;
    int _florin;
    std::string _wagon_type;
};

#endif //CPLUS_WAGON_HPP
