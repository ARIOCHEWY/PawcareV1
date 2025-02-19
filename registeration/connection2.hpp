#ifndef SQL_CONNECT
#define SQL_CONNECT
#include <Windows.h>
#include <sqlext.h>
#include <sql.h>
#include <iostream>
#include <vector>
#include <string>

SQLHDBC Sql_connect(SQLHENV& env);
void fetch_data(SQLHDBC dbc);
void add_data(SQLHDBC dbc);
void remove_data(SQLHDBC dbc);
void create_table(SQLHDBC dbc);
void remove_table(SQLHDBC dbc);



void closeConnection(SQLHENV env, SQLHDBC dbc);





#endif