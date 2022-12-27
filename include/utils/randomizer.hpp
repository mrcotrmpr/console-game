#ifndef CPLUS_RANDOMIZER_HPP
#define CPLUS_RANDOMIZER_HPP

#include <random>

class Randomizer
{
public:
	int get_int_between_values(const int first, const int second);
private:
	std::mt19937 engine{ std::random_device{}() };
};

#endif //CPLUS_RANDOMIZER_HPP
