#ifndef CPLUS_HARBOR_HPP
#define CPLUS_HARBOR_HPP

#include "string"
#include "vector"
#include <memory>

#include "models/sqlite_model.hpp"

class Good;
class Cannon;
class Ship;
class Destination;

class Harbor : public SQLiteModel
{
public:
    Harbor() = default;
    Harbor(int harbor_id, std::string harbor_name);
    [[nodiscard]] int get_harbor_id() const;
    [[nodiscard]] std::string get_harbor_name() const;
    [[nodiscard]] std::vector <std::shared_ptr<Good>> get_goods() const;
    [[nodiscard]] std::vector <std::shared_ptr<Cannon>> get_cannons() const;
    [[nodiscard]] std::vector <std::shared_ptr<Ship>> get_ships() const;
    [[nodiscard]] std::vector <std::shared_ptr<Destination>> get_destinations() const;
    [[nodiscard]] std::shared_ptr<Good> get_good(int id) const;
    [[nodiscard]] std::shared_ptr<Cannon> get_cannon(int id) const;
    [[nodiscard]] std::shared_ptr<Ship> get_ship(int id) const;
    void set_goods(const std::vector<std::shared_ptr<Good>>& goods);
    void set_cannons(const std::vector<std::shared_ptr<Cannon>>& cannons);
    void set_ships(const std::vector<std::shared_ptr<Ship>>& ships);
    void set_destinations(const std::vector<std::shared_ptr<Destination>>& destinations);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _harbor_id{};
    std::string _harbor_name;
    std::vector<std::shared_ptr<Good>> _goods;
    std::vector<std::shared_ptr<Cannon>> _cannons;
    std::vector<std::shared_ptr<Ship>> _ships;
    std::vector<std::shared_ptr<Destination>> _destinations;
};

#endif //CPLUS_HARBOR_HPP
