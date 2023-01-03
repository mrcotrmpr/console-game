#ifndef CPLUS_CANNON_HPP
#define CPLUS_CANNON_HPP

#include <string>
#include "models/sqlite_model.hpp"

class Cannon : public SQLiteModel
{
public:
    Cannon() = default;
    Cannon(int cannon_id, std::string cannon_name);
    [[nodiscard]] int get_cannon_id() const;
    [[nodiscard]] int get_cannon_price() const;
    [[nodiscard]] int get_damage() const;
    [[nodiscard]] int get_amount() const;
    [[nodiscard]] int get_min_amount() const;
    [[nodiscard]] int get_max_amount() const;
    [[nodiscard]] int get_min_damage() const;
    [[nodiscard]] int get_max_damage() const;
    [[nodiscard]] std::string get_cannon_name() const;
    void set_amount(int amount);
    void set_damage(int damage);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _cannon_id{};
    int _min_amount{};
    int _max_amount{};
    int _price{};
    int _damage{};
    int _amount{};
    int _min_damage{};
    int _max_damage{};
    std::string _cannon_name;
};

#endif //CPLUS_CANNON_HPP
