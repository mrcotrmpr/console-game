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
    [[nodiscard]] std::string get_good_name() const;
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _good_id;
    std::string _good_name;
};

#endif //CPLUS_GOOD_HPP
