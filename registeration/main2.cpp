//#include "CRUDV2.cpp"
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    DatabaseHandler db;
//    if (db.connect()) {
//        // Example: Insert a new record
//        wstring insertQuery = L"INSERT INTO Account_holders (HolderEmail, FirstName, LastName, BirthDate, EmailVerified, CreatedAt, UpdatedAt) "
//            L"VALUES ('test.user@example.com', 'Test', 'User', '1995-08-22', 1, GETDATE(), GETDATE())";
//
//        if (db.add_data(insertQuery)) {
//            cout << "Record inserted successfully!" << endl;
//        }
//
//        // Fetch data after insertion
//        vector<vector<wstring>> data;
//        if (db.fetch_data(L"SELECT * FROM Account_holders", data)) {
//            for (const auto& row : data) {
//                for (const auto& col : row) {
//                    wcout << col << L"\t";
//                }
//                wcout << endl;
//            }
//        }
//
//        // Example: Delete the record we just inserted
//        wstring deleteQuery = L"DELETE FROM Account_holders WHERE HolderEmail = 'test.user@example.com'";
//
//        if (db.remove_data(deleteQuery)) {
//            cout << "Record deleted successfully!" << endl;
//        }
//
//        // Fetch data again to verify deletion
//        if (db.fetch_data(L"SELECT * FROM Account_holders", data)) {
//            for (const auto& row : data) {
//                for (const auto& col : row) {
//                    wcout << col << L"\t";
//                }
//                wcout << endl;
//            }
//        }
//    }
//    return 0;
//}
