#ifndef CPLUS_SQLITE_MODEL_HPP
#define CPLUS_SQLITE_MODEL_HPP

class SQLiteModel
{
public:
    virtual void set_int_value(const char* column_name, int value) = 0;
    virtual void set_string_value(const char* column_name, const char* value) = 0;
};

#endif //CPLUS_SQLITE_MODEL_HPP
