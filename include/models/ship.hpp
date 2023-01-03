#ifndef CPLUS_SHIP_HPP
#define CPLUS_SHIP_HPP

#include <string>
#include <vector>
#include <memory>
#include "models/sqlite_model.hpp"

class Good;
class Cannon;

class Ship : public SQLiteModel
{
public:
    Ship() = default;
    Ship(int ship_id, std::string ship_type);
    [[nodiscard]] int get_ship_id() const;
    [[nodiscard]] int get_ship_price() const; 
    [[nodiscard]] int get_gold() const;
    [[nodiscard]] int get_health() const; 
    [[nodiscard]] int get_max_health() const;
    [[nodiscard]] int get_max_goods_kg() const;
    [[nodiscard]] int get_goods_kg_used() const;
    [[nodiscard]] int get_max_cannons() const;
    [[nodiscard]] int get_cannons_used() const;
    [[nodiscard]] std::vector<std::shared_ptr<Good>> get_goods() const;
    [[nodiscard]] std::vector<std::shared_ptr<Cannon>> get_cannons() const;
    [[nodiscard]] std::shared_ptr<Good> get_good(int id) const;
    [[nodiscard]] std::shared_ptr<Cannon> get_cannon(int id) const;
    [[nodiscard]] std::string get_ship_type() const;
    void remove_good(int id, int amount);
    void remove_cannon(int id, int amount);
    void set_gold(int amount);
    void set_health(int amount);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
    void add_good(const std::shared_ptr<Good>&, int amount);
    void add_cannon(const std::shared_ptr<Cannon>&, int amount);
private:
    int _ship_id{};
    int _price{};
    int _max_goods_kg{};
    int _max_cannons{};
    int _health{};
    int _max_health{};
    int _gold{};
    int _goods_kg_used{};
    int _cannons_used{};
    std::string _ship_type;
    std::vector<std::shared_ptr<Good>> _goods;
    std::vector<std::shared_ptr<Cannon>> _cannons;
};

#endif //CPLUS_SHIP_HPP
