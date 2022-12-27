#ifndef CPLUS_FIREARM_HPP
#define CPLUS_FIREARM_HPP

#include <string>

class Firearm
{
public:
    Firearm(const int firearm_id, const std::string& firearm_name);
    [[nodiscard]] int get_firearm_id() const;
    [[nodiscard]] std::string get_firearm_name() const;
private:
    int _firearm_id;
    const std::string& _firearm_name;
};

#endif //CPLUS_FIREARM_HPP
