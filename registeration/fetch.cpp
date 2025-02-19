//#include "connection.h"
//
//void fetchData(SQLHDBC dbc) {
//    SQLHSTMT stmt;
//    SQLRETURN ret;
//
//    // Allocate a statement handle
//    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//
//    // Execute the query
//    SQLWCHAR sqlQuery[] = L"SELECT customerID, firstname, lastname FROM customers;";
//    ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//
//    if (SQL_SUCCEEDED(ret)) {
//        SQLINTEGER customerID;
//        SQLWCHAR firstname[50], lastname[50];
//
//        // Bind columns to variables
//        SQLBindCol(stmt, 1, SQL_C_SLONG, &customerID, 0, NULL);
//        SQLBindCol(stmt, 2, SQL_C_WCHAR, firstname, sizeof(firstname), NULL);
//        SQLBindCol(stmt, 3, SQL_C_WCHAR, lastname, sizeof(lastname), NULL);
//
//        
//        while (SQLFetch(stmt) == SQL_SUCCESS) {
//            wcout << L"ID: " << customerID << L", First Name: " << firstname << L", Last Name: " << lastname << endl;
//        }
//    }
//    else {
//        wcerr << L"Failed to execute query." << endl;
//    }
//
//    // Free the statement handle
//    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//}
//
//int main() {
//    SQLHENV env;
//    SQLHDBC dbc = establishConnection(env);
//
//    if (dbc) {
//        fetchData(dbc);       // Fetch data from the table
//        closeConnection(env, dbc);  // Close the connection
//    }
//
//    return 0;
//}
