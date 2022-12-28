#ifndef CPLUS_GOOD_HPP
#define CPLUS_GOOD_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Good : public SQLiteModel
{
public:
    Good() = default;
    Good(const int good_id, const std::string& good_name);
    [[nodiscard]] int get_good_id() const;
    [[nodiscard]] int get_price() const;
    [[nodiscard]] int get_amount() const;
    [[nodiscard]] int get_min_amount() const;
    [[nodiscard]] int get_max_amount() const;
    [[nodiscard]] int get_min_price() const;
    [[nodiscard]] int get_max_price() const;
    [[nodiscard]] std::string get_good_name() const;
    void set_price(const int price);
    void set_amount(const int amount);
    void set_name(std::string name);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _good_id;
    int _price;
    int _amount;
    int _min_amount;
    int _max_amount;
    int _min_price;
    int _max_price;
    std::string _good_name;
};

#endif //CPLUS_GOOD_HPP
