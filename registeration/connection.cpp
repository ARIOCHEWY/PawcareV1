//#include "connection.h"
//
//SQLHDBC establishConnection(SQLHENV &env) {
//    SQLHDBC dbc;
//    SQLRETURN ret;
//
//    // Allocate environment handle and set ODBC version
//    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
//    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
//
//    // Allocate the connection handle
//    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
//
//    // Connection string
//    SQLWCHAR connStr[] = L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=ARIOLAP\\SQLEXPRESS;DATABASE=PawcareDB;Trusted_Connection=Yes;";
//
//    // Attempt to connect
//    ret = SQLDriverConnect(dbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
//
//    if (SQL_SUCCEEDED(ret)) {
//        wcout << L"Connected to the database successfully!" << endl;
//        return dbc;  // Return the connection handle
//    }
//    else {
//        wcerr << L"Failed to connect to the database." << endl;
//        SQLFreeHandle(SQL_HANDLE_DBC, dbc);
//        SQLFreeHandle(SQL_HANDLE_ENV, env);
//        return nullptr;  // Return nullptr on failure
//    }
//}
//
//void closeConnection(SQLHENV env, SQLHDBC dbc) {
//    // Disconnect and free handles
//    if (dbc) SQLDisconnect(dbc);
//    if (dbc) SQLFreeHandle(SQL_HANDLE_DBC, dbc);
//    if (env) SQLFreeHandle(SQL_HANDLE_ENV, env);
//}
