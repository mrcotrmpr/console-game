#ifndef CPLUS_HARBOR_HPP
#define CPLUS_HARBOR_HPP

#include "string"
#include "vector"
#include <memory>

#include "models/sqlite_model.hpp"

class Good;

class Harbor : public SQLiteModel
{
public:
    Harbor() = default;
    Harbor(int harbor_id, const std::string& harbor_name);
    [[nodiscard]] int get_harbor_id() const;
    [[nodiscard]] std::string get_harbor_name() const;
    [[nodiscard]] std::vector <std::shared_ptr<Good>> get_goods() const;
    void set_goods(std::vector<std::shared_ptr<Good>> goods);
    void set_int_value(const char* column_name, int value) override;
    void set_string_value(const char* column_name, const char* value) override;
private:
    int _harbor_id;
    std::string _harbor_name;
    std::vector<std::shared_ptr<Good>> _goods;
};

#endif //CPLUS_HARBOR_HPP
