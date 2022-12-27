#include "utils/randomizer.hpp"

int Randomizer::get_int_between_values(const int first, const int second)
{
	std::uniform_int_distribution<int> dist{ first, second };
	return dist(engine);
}
