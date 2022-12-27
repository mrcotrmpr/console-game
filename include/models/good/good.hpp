#ifndef CPLUS_GOOD_HPP
#define CPLUS_GOOD_HPP

#include <string>

class Good
{
public:
    Good(const int good_id, const std::string& good_name);
    [[nodiscard]] int get_good_id() const;
    [[nodiscard]] std::string get_good_name() const;
private:
    int _good_id;
    const std::string& _good_name;
};

#endif //CPLUS_GOOD_HPP
