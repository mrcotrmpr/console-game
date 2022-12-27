#ifndef CPLUS_TOWN_HPP
#define CPLUS_TOWN_HPP

#include "string"

class Town
{
public:
    Town();
    Town(const int town_id, const std::string& town_name);
    [[nodiscard]] int get_town_id() const;
    [[nodiscard]] std::string get_town_name() const;
    void set_int_value(const char* column_name, int value);
    void set_string_value(const char* column_name, const char* value);
private:
    int _town_id;
    std::string _town_name;
};

#endif //CPLUS_TOWN_HPP
