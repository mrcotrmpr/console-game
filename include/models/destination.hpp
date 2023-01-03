#ifndef CPLUS_DESTINATION_HPP
#define CPLUS_DESTINATION_HPP

#include "models/sqlite_model.hpp"

#include "string"

class Destination : public SQLiteModel
{
public:
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
    void set_name(const std::string& name);
    void increase_turn();
    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] int get_from_id() const;
    [[nodiscard]] int get_to_id() const;
    [[nodiscard]] int get_distance() const;
    [[nodiscard]] int get_turn() const;
private:
    std::string _destination_name;
    int _from_destination_id;
    int _to_destination_id;
    int _distance;
    int _turn = 0;
};

#endif //CPLUS_DESTINATION_HPP
