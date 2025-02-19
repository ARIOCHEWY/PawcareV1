//#include "connection2.hpp"
//#include <Windows.h>
//#include <iostream>
//#include <locale>
//#include <codecvt>
//
//using namespace std;
//
//
//SQLHDBC Sql_connect(SQLHENV& env) {
//	SQLHDBC dbc;
//	SQLRETURN ret; 
//
//	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
//	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
//	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
//
//	SQLWCHAR con[] = L"{ODBC Driver 17 for SQL Server};SERVER=ARIOLAP\\SERVEREXPRESS;DATABASE=PawcareDB;Trusted_Connection=Yes;";
//	ret = SQLDriverConnect(dbc, NULL, con, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
//
//	if (SQL_SUCCEEDED(ret)) {
//		wcout << L" connected to database!" << endl;
//		return dbc;
//	}
//	else
//	{
//		wcerr << L"The connection was unsuccessful" << endl;
//		SQLFreeHandle(SQL_HANDLE_DBC, dbc);
//		SQLFreeHandle(SQL_HANDLE_ENV, env);
//	}
//}
//
//void fetch_data(SQLHDBC dbc, vector<string> &buffer) {
//	SQLHSTMT stmt;
//	SQLRETURN ret;
//
//	SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//	SQLWCHAR sqlQuery[] = L"SELECT HolderEmail FROM Account_holders;";
//	ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//
//	if (SQL_SUCCEEDED(ret)) {
//		SQLWCHAR HolderEmail[50];
//
//		SQLBindCol(stmt, 1, SQL_C_WCHAR, HolderEmail, sizeof(HolderEmail), NULL);
//		wstring_convert<codecvt_utf8<wchar_t>> converter;
//
//
//		while (SQLFetch(stmt) == SQL_SUCCESS) {
//			string email = converter.to_bytes(HolderEmail);
//			buffer.push_back(email);
//
//		}
//	}
//	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//
//}
//
//void add_data(SQLHDBC dbc) {
//	SQLHSTMT stmt;
//	SQLRETURN ret;
//
//	// Allocate a statement handle
//	SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//
//	// SQL INSERT statement with placeholders (?)
//	SQLWCHAR sqlQuery[] = L"INSERT INTO Account_holders (HolderEmail, FirstName, LastName, BirthDate, Age, EmailVerified) VALUES (?, ?, ?, ?, ?, ?);";
//
//	// Sample data to insert
//	SQLWCHAR HolderEmail[] = L"newuser@example.com";
//	SQLWCHAR FirstName[] = L"John";
//	SQLWCHAR LastName[] = L"Doe";
//	SQLWCHAR BirthDate[] = L"1995-08-20";  // Format YYYY-MM-DD
//	SQLINTEGER Age = 28;
//	SQLINTEGER EmailVerified = 1;
//
//	// Bind parameters
//	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, sizeof(HolderEmail), 0, HolderEmail, 0, NULL);
//	SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, sizeof(FirstName), 0, FirstName, 0, NULL);
//	SQLBindParameter(stmt, 3, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, sizeof(LastName), 0, LastName, 0, NULL);
//	SQLBindParameter(stmt, 4, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, sizeof(BirthDate), 0, BirthDate, 0, NULL);
//	SQLBindParameter(stmt, 5, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &Age, 0, NULL);
//	SQLBindParameter(stmt, 6, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_INTEGER, 0, 0, &EmailVerified, 0, NULL);
//
//	// Execute the SQL command
//	ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//
//	// Check if the insertion was successful
//	if (SQL_SUCCEEDED(ret)) {
//		wcout << L"New account holder added successfully!" << endl;
//	}
//	else {
//		wcerr << L"Failed to add new account holder." << endl;
//	}
//
//	// Free the statement handle
//	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//}
//
//void remove_data(SQLHDBC dbc) {
//	SQLHSTMT stmt;
//	SQLRETURN ret;
//
//	// Allocate a statement handle
//	SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//
//	// SQL DELETE statement with a parameter (?)
//	SQLWCHAR sqlQuery[] = L"DELETE FROM Account_holders WHERE HolderEmail = ?;";
//
//	// The email to delete (modify as needed)
//	SQLWCHAR HolderEmail[] = L"newuser@example.com";
//
//	// Bind the HolderEmail parameter to the DELETE statement
//	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR, sizeof(HolderEmail), 0, HolderEmail, 0, NULL);
//
//	// Execute the DELETE command
//	ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//
//	// Check if the execution was successful
//	if (SQL_SUCCEEDED(ret)) {
//		wcout << L"Account holder '" << HolderEmail << L"' removed successfully!" << endl;
//	}
//	else {
//		wcerr << L"Failed to remove account holder." << endl;
//	}
//
//	// Free the statement handle
//	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//}