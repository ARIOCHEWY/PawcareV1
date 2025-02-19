//// For establishing a connection with windows.h
//#include <windoows.h>
//#include <slql.h>
//#include <sqltext.h>
//#include <iostream>
//
//
//SQLHDBC connction(SQLENV &enviro) {
//	SQLHDBC dbc;
//	SQLRETURN env;
//
//
//	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
//
//	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
//
//	SQLSetAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
//
//	SQLWCHAR = L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=ARIOLAP\\SQLEXPRESS;DATABASE=PawcareDB;Trusted_Connection=Yes;";
//	
//	ret = SQLDriverConnect(dbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
//
//	if (SQL_SUCCEEDED(ret)) {
//		wcout << L"Connection has been established" << endl;
//		return dbc;
//	}
//	else {
//		wcerr < L"Failed to establish a connection" << endl;
//		SQLFreeHandle(SQL_Handle_DBC, dbc);
//		SQLFreeHandle(SQL_Handle_ENV, env);
//		return nullptr;
//	}
//
//}


//template <typename T1, typename T2>
//void fetch_data(SQLWCHAR sqlQuery[], vector<pair<T1, T2>>& results) {
//	SQLHDBC dbc = this->connection();
//	//if the connection fails
//	if (!dbc) return;
//
//
//	SQLHSTMT stmt;
//	SQLRETURN ret;
//
//	//allocate handle
//	SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
//	//execute query
//	ret = SQLExecDirect(stmt, sqlQuery, SQL_NTS);
//
//	if (SQL_SUCCEEDED(ret)) {
//		T1 Col1;
//		T2 Col2;
//		SQLLEN cbCol1, cbCol2;
//
//		if constexpr (is_same<T1, wstring>::value) {
//			Col1.resize(100);  // ✅ Allocate space for wstring
//		}
//
//		//determining SQL C type based on T1 and T2
//		auto SQL_C_TYPE_1 = is_same<T1, wstring>::value ? SQL_C_WCHAR :
//			is_same<T1, string> ::value ? SQL_C_CHAR :
//			SQL_C_DEFAULT;
//		auto SQL_C_TYPE_2 = is_same<T2, int>::value ? SQL_C_LONG :
//			is_same<T2, double>::value ? SQL_C_DOUBLE :
//			SQL_C_DEFAULT;
//
//
//		SQLBindCol(stmt, 1, SQL_C_TYPE_1, &Col1, sizeof(Col1), &cbCol1);
//		SQLBindCol(stmt, 2, SQL_C_TYPE_2, &Col2, 0, &cbCol2);
//
//
//		while (SQLFetch(stmt) == SQL_SUCCESS) {
//			if (cbCol1 != SQL_NULL_DATA) {
//				results.emplace_back(Col1, Col2);
//			}
//		}
//	}
//	SQLFreeHandle(SQL_HANDLE_STMT, stmt);
//
//}
