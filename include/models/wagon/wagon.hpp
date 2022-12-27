#ifndef CPLUS_WAGON_HPP
#define CPLUS_WAGON_HPP

#include <string>

class Wagon
{
public:
    Wagon(const int wagon_id, const std::string& wagon_type);
    [[nodiscard]] int get_wagon_id() const;
    [[nodiscard]] std::string get_wagon_type() const;
private:
    int _wagon_id;
    const std::string& _wagon_type;
};

#endif //CPLUS_WAGON_HPP
