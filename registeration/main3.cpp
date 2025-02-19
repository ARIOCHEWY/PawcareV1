#include "CRUDV2.cpp"
#include <iostream>

using namespace std;

int main() {
	DatabaseHandler db;
	vector<vector<wstring>> data;

	if (!db.connect()) {
		cout << "cannot connect to database! " << endl;
	}
	else {
		cout << "You are connected to the database! " << endl;
	}
	string TempQuery;
	cout << "Enter SQL Query:  " <<endl;
	cin.ignore();
	getline(cin, TempQuery);
	wstring query(TempQuery.begin(), TempQuery.end());

	db.fetch_data(query, data);

	for (auto RowInfo : data) {
		for (auto ColInfo : RowInfo) {
			wcout << "Line:  " << ColInfo << endl;
		}	
	}
	
	//if (db.fetch_data()) {
	//	data.push_back()
	//}


	return 0;
}