//#include <iostream>
//#include <Windows.h>
//#include <sql.h>
//#include <sqlext.h>
//#include <codecvt>
//#include <vector>
//
//// this is my class to begin programming
//using namespace std;
//template<class crud>
//class Operations {
//private:
//	SQLHENV environment;
//	//SQLHENV database;
//	//SQLHENV statements;
//public:
//	//constructor
//	Operations(SQLHENV env) : environment(env) {
//		SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&environment);
//		SQLSetEnvAttr(environment, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3,0);
//	}
//
//	SQLHDBC connection() {
//		SQLHDBC dbc;
//		SQLRETURN ret;
//		
//		//allocate handles
//		SQLAllocHandle(SQL_HANDLE_DBC, environment, &dbc);
//        SQLWCHAR conn[] = L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=ARIOLAP\\SQLEXPRESS;DATABASE=PawcareDB;Trusted_Connection=YES;";
//        
//		ret = SQLDriverConnect(dbc, NULL, conn, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
//		if (SQL_SUCCEEDED(ret)) {
//			wcout << L"You Have Connected to the Database" << endl;
//			return dbc;
//		}
//		else
//		{
//			wcout << L"The Connection was Unsuccesful" << endl;
//			SQLFreeHandle(SQL_HANDLE_DBC, dbc);
//			return nullptr;
//		}
//		
//	}
//
//    template <typename T1, typename T2>
//    void fetch_data(SQLWCHAR sqlQuery[], vector<pair<T1, T2>>& results) {
//        SQLHDBC dbc = this->connection();
//        if (!dbc) return;
//
//        SQLHSTMT stmt;
//        SQLRETURN ret;
//
//        SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//        ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//        if (!SQL_SUCCEEDED(ret)) {
//            wcout << L"SQL Query Execution Failed!" << endl;
//            SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//            SQLFreeHandle(SQL_HANDLE_DBC, dbc);
//            return;
//        }
//
//        typename conditional<is_same<T1, wstring>::value, wstring, T1>::type Col1;
//        T2 Col2;
//        SQLLEN cbCol1, cbCol2;
//
//        wchar_t Col1Buffer[100];  // Buffer for NVARCHAR
//        if constexpr (is_same<T1, wstring>::value) {
//            SQLBindCol(stmt, 1, SQL_C_WCHAR, Col1Buffer, sizeof(Col1Buffer), &cbCol1);
//        }
//        else if constexpr (is_same<T1, string>::value) {
//            SQLBindCol(stmt, 1, SQL_C_CHAR, &Col1, sizeof(Col1), &cbCol1);
//        }
//        else {
//            SQLBindCol(stmt, 1, SQL_C_DEFAULT, &Col1, sizeof(Col1), &cbCol1);
//        }
//
//        auto SQL_C_TYPE_2 = is_same<T2, int>::value ? SQL_C_LONG :
//                            is_same<T2, double>::value ? SQL_C_DOUBLE :
//                            SQL_C_DEFAULT;
//
//        SQLBindCol(stmt, 2, SQL_C_TYPE_2, &Col2, 0, &cbCol2);
//
//        while (SQLFetch(stmt) == SQL_SUCCESS) {
//           if (cbCol1 != SQL_NULL_DATA) {
//              if constexpr (is_same<T1, wstring>::value) {
//                 Col1 = wstring(Col1Buffer);  //  Convert buffer to `wstring`
//              }
//              results.emplace_back(Col1, Col2);
//           }
//        }
//        
//
//        //  Free Handles
//        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//        
//    }
//
//	
//};
