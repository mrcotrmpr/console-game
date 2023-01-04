#ifndef CPLUS_SHIP_HPP
#define CPLUS_SHIP_HPP

#include <string>
#include <vector>
#include <memory>
#include "models/sqlite_model.hpp"
#include "utils/randomizer.hpp"

class Good;
class Cannon;
class Destination;

class Ship : public SQLiteModel, public std::enable_shared_from_this<Ship>
{
public:
    Ship() = default;
    Ship(const Ship &other);
    Ship(int ship_id, std::string ship_type);
    [[nodiscard]] std::string get_ship_type() const;
    [[nodiscard]] std::string get_specialty() const;
    [[nodiscard]] int get_ship_id() const;
    [[nodiscard]] int get_ship_price() const; 
    [[nodiscard]] int get_gold() const;
    [[nodiscard]] int get_health() const; 
    [[nodiscard]] int get_max_health() const;
    [[nodiscard]] int get_max_goods_kg() const;
    [[nodiscard]] int get_goods_kg_used() const;
    [[nodiscard]] int get_max_cannons() const;
    [[nodiscard]] int get_cannons_used() const;
    [[nodiscard]] int get_fighting_state() const;
    [[nodiscard]] int get_cannons_damage() const;
    [[nodiscard]] std::vector<std::shared_ptr<Good>> get_goods() const;
    [[nodiscard]] std::vector<std::shared_ptr<Cannon>> get_cannons() const;
    [[nodiscard]] std::shared_ptr<Good> get_good(int id) const;
    [[nodiscard]] std::shared_ptr<Cannon> get_cannon(int id) const;
    [[nodiscard]] std::shared_ptr<Destination> get_destination() const;
    void set_destination(const std::shared_ptr<Destination>&);
    void set_fighting_state(bool state);
    void remove_good(int id, int amount);
    void remove_cannon(int id, int amount);
    void set_specialty(const std::string& specialty);
    void set_gold(int amount);
    void set_health(int amount);
    void set_goods_used(int amount);
    void set_cannons_used(int amount);
    void set_goods(std::vector<std::shared_ptr<Good>>);
    void set_cannons(std::vector<std::shared_ptr<Cannon>>);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
    void add_good(const std::shared_ptr<Good>& goods, int amount);
    void add_cannon(const std::shared_ptr<Cannon>& cannons, int amount);
    void clear_cargo();
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
    std::string _specialty;
    std::vector<std::shared_ptr<Good>> _goods;
    std::vector<std::shared_ptr<Cannon>> _cannons;
    std::shared_ptr<Destination> _destination;
    bool _fighting = false;
    std::shared_ptr<Randomizer> _random = std::make_shared<Randomizer>();
};

#endif //CPLUS_SHIP_HPP
