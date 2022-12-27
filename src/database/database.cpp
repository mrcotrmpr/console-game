#include "database/database.hpp"

//#include "sqlite3.h"

std::shared_ptr<sqlite> Database::get_connection() const
{
	return std::shared_ptr<sqlite>();
}

template<typename T>
inline T Database::get_entity(std::shared_ptr<sqlite>, const std::string sql)
{
	return T();
}
