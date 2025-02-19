//#include "CRUD.cpp"
//#include <iostream>
//using namespace std;
//
//int main() {
//	Operations<string>dbOperations(nullptr);
//	vector<pair<int, wstring>>results;
//
//	SQLWCHAR query[] = L"SELECT * FROM Account_Holders;";
//
//
//	dbOperations.fetch_data(query, results);
//
//	wcout << L"\nFetched Data:\n";
//	for (const auto& [id,name] : results) {
//		wcout << L"ID: " << id << L", Name: " << name.c_str() << endl;  // ✅ FIXED
//	}
//
//	return 0;
//}