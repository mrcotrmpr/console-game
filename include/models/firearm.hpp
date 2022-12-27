#ifndef CPLUS_FIREARM_HPP
#define CPLUS_FIREARM_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Firearm : public SQLiteModel
{
public:
    Firearm() = default;
    Firearm(const int firearm_id, const std::string& firearm_name);
    [[nodiscard]] int get_firearm_id() const;
    [[nodiscard]] int get_firearm_price() const;
    [[nodiscard]] std::string get_firearm_name() const;
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _firearm_id;
    int _min_amount;
    int _max_amount;
    int _price;
    int _min_damage;
    int _max_damage;
    std::string _firearm_name;
};

#endif //CPLUS_FIREARM_HPP
