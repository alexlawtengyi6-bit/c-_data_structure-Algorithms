#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <json/json.h> // Requires installing a JSON library (e.g., nlohmann_json)

// --- Login/Signup System ---
void signupUser(const std::string& username, const std::string& password) {
    // TODO:  Save username/password to a file or database.
    std::cout << "Signing up user: " << username << std::endl;
}

bool loginUser(const std::string& username, const std::string& password) {
    // TODO:  Check username/password against stored data.
    std::cout << "Logging in user: " << username << std::endl;
    return true; // Placeholder - Replace with actual login logic
}


// --- Algorithm Implementation (Example: Bubble Sort) ---
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}



// --- Data Storage ---
void saveToJSON(const std::vector<int>& data, const std::string& filename) {
    Json::Value root;
    root["data"] = data;
    Json::StreamWriter stream;
    std::ofstream outputFile(filename);
    stream.write(root);
    outputFile.close();
}


void saveToSQLite(const std::vector<int>& data, const std::string& dbFilename) {
    sqlite3 *db;
    char *sql;
    int rc;

    rc = sqlite3_open(dbFilename.c_str(), &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sql = "CREATE TABLE IF NOT EXISTS results (id INTEGER PRIMARY KEY AUTOINCREMENT, value INTEGER)";
    rc = sqlite3_exec(db, sql, NULL, NULL, &rc);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
    }

    for (size_t i = 0; i < data.size(); i++) {
        std::string insertStatement = "INSERT INTO results (value) VALUES (?)";
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, insertStatement.c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        }
        rc = sqlite3_bind_int64(stmt, 1, data[i]);
        if (rc != SQLITE_OK) {
            std::cerr << "Error binding value: " << sqlite3_errmsg(db) << std::endl;
        }
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
}


int main() {
    // --- Example Usage ---
    std::vector<int> myData = {5, 2, 8, 1, 9};

    signupUser("user1", "password123");

    if (loginUser("user1", "password123")) {
        bubbleSort(myData);

        saveToJSON(myData, "results.json");
        saveToSQLite(myData, "results.db");

        std::cout << "Data saved to JSON and SQLite!" << std::endl;
    }

    return 0;
}
