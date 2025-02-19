#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;

class DatabaseHandler {
private:
    SQLHANDLE sqlEnvHandle;
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLRETURN retCode;

public:
    DatabaseHandler() {
        sqlEnvHandle = NULL;
        sqlConnHandle = NULL;
        sqlStmtHandle = NULL;
    }

    // Function to establish a connection
    bool connect() {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
            cerr << "Failed to allocate environment handle" << endl;
            return false;
        }

        if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
            cerr << "Failed to set environment attribute" << endl;
            return false;
        }

        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
            cerr << "Failed to allocate connection handle" << endl;
            return false;
        }

        wstring connStr = L"DRIVER={SQL Server};SERVER=ARIOLAP\\SQLEXPRESS;DATABASE=PawcareDB;Trusted_Connection=Yes;";
        retCode = SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)connStr.c_str(), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);

        if (SQL_SUCCESS != retCode && SQL_SUCCESS_WITH_INFO != retCode) {
            cerr << "Database connection failed" << endl;
            return false;
        }

        cout << "Connected to the database successfully!" << endl;
        return true;
    }

    // Function to fetch data from SQL Server
    bool fetch_data(wstring query, vector<vector<wstring>>& results) {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
            cerr << "Failed to allocate statement handle" << endl;
            return false;
        }

        retCode = SQLExecDirectW(sqlStmtHandle, (SQLWCHAR*)query.c_str(), SQL_NTS);
        if (SQL_SUCCESS != retCode && SQL_SUCCESS_WITH_INFO != retCode) {
            cerr << "Error executing SQL query." << endl;
            return false;
        }

        SQLSMALLINT numColumns;
        SQLNumResultCols(sqlStmtHandle, &numColumns);

        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            vector<wstring> row;
            for (SQLSMALLINT i = 1; i <= numColumns; i++) {
                SQLLEN dataLen;
                SQLSMALLINT colType;
                SQLDescribeCol(sqlStmtHandle, i, NULL, 0, NULL, &colType, NULL, NULL, NULL);

                if (colType == SQL_INTEGER) {
                    SQLINTEGER intData;
                    SQLGetData(sqlStmtHandle, i, SQL_C_LONG, &intData, sizeof(intData), &dataLen);
                    row.push_back(to_wstring(intData));
                }
                else {
                    SQLWCHAR data[256];
                    SQLGetData(sqlStmtHandle, i, SQL_C_WCHAR, data, sizeof(data), &dataLen);
                    row.push_back((wchar_t*)data);
                }
            }
            results.push_back(row);
        }

        return true;
    }

    // Function to insert data into SQL Server
    bool add_data(wstring query) {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
            cerr << "Failed to allocate statement handle" << endl;
            return false;
        }

        retCode = SQLExecDirectW(sqlStmtHandle, (SQLWCHAR*)query.c_str(), SQL_NTS);

        if (SQL_SUCCESS != retCode && SQL_SUCCESS_WITH_INFO != retCode) {
            cerr << "Error executing INSERT query." << endl;
            SQLWCHAR sqlState[6], message[256];
            SQLINTEGER nativeError;
            SQLSMALLINT msgLen;

            while (SQLErrorW(sqlEnvHandle, sqlConnHandle, sqlStmtHandle, sqlState, &nativeError, message, 255, &msgLen) == SQL_SUCCESS) {
                wcerr << L"SQL Error State: " << sqlState << L", Error Code: " << nativeError << L", Message: " << message << endl;
            }

            return false;
        }

        cout << "Data inserted successfully!" << endl;
        return true;
    }

    // Function to remove data from SQL Server
    bool remove_data(wstring query) {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
            cerr << "Failed to allocate statement handle" << endl;
            return false;
        }

        retCode = SQLExecDirectW(sqlStmtHandle, (SQLWCHAR*)query.c_str(), SQL_NTS);

        if (SQL_SUCCESS != retCode && SQL_SUCCESS_WITH_INFO != retCode) {
            cerr << "Error executing DELETE query." << endl;
            SQLWCHAR sqlState[6], message[256];
            SQLINTEGER nativeError;
            SQLSMALLINT msgLen;

            while (SQLErrorW(sqlEnvHandle, sqlConnHandle, sqlStmtHandle, sqlState, &nativeError, message, 255, &msgLen) == SQL_SUCCESS) {
                wcerr << L"SQL Error State: " << sqlState << L", Error Code: " << nativeError << L", Message: " << message << endl;
            }

            return false;
        }

        cout << "Data deleted successfully!" << endl;
        return true;
    }

    ~DatabaseHandler() {
        SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
        SQLDisconnect(sqlConnHandle);
        SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
        SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
    }
};
