#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// ... (Previous UserAccount class and TopUpSystem class) ...

// Function to save UserAccount data to a CSV file
void saveUserAccountsToCSV(const std::vector<UserAccount>& userAccounts, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outputFile << "id,username,password_hash,top_up_amount,last_top_up_amount" << std::endl;
    for (const auto& user : userAccounts) {
        outputFile << user.id << "," << user.username << "," << user.password_hash << ","
                   << user.top_up_amount << "," << user.last_top_up_amount << std::endl;
    }

    outputFile.close();
}

// Function to load UserAccount data from a CSV file
std::vector<UserAccount> loadUserAccountsFromCSV(const std::string& filename) {
    std::vector<UserAccount> userAccounts;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return userAccounts;
    }

    std::string line;
    std::getline(inputFile, line); // Skip header line

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> values;
        while (std::getline(ss, token, ',')) {
            values.push_back(token);
        }

        if (values.size() == 5) { // Ensure correct number of columns
            int id = std::stoi(values[0]);
            std::string username = values[1];
            std::string password_hash = values[2];
            double top_up_amount = std::stod(values[3]);
            double last_top_up_amount = std::stod(values[4]);

            UserAccount ua(id, username, password_hash, top_up_amount);
            ua.last_top_up_amount = last_top_up_amount;
            userAccounts.push_back(ua);
        }
    }

    inputFile.close();
    return userAccounts;
}

// ... (Previous TopUpSystem class structure) ...

void TopUpSystem::saveUserAccounts() {
    saveUserAccountsToCSV(userAccounts, "user_accounts.csv");
}

void TopUpSystem::loadUserAccounts() {
    userAccounts = loadUserAccountsFromCSV("user_accounts.csv");
}

// Placeholder for delete function - implement database delete operation
void TopUpSystem::deleteUserAccount(int userId) {
    // Implement database delete operation here
    std::cout << "Deleting user with ID: " << userId << std::endl;
}

// Placeholder for update function - Implement database update operation here
void TopUpSystem::updateUserTopUpAmount(int userId, double newTopUpAmount) {
   //Implement database update operation here
    std::cout << "Updating top-up amount for user " << userId << " to " << newTopUpAmount << std::endl;
}

int main() {
    TopUpSystem system;
    system.loadUserAccounts(); // Load existing user accounts (if any)

    // Create a new user account
    system.addUser("testuser", "password123");
    system.saveUserAccounts();

    //Update the top up amount
    system.updateUserTopUpAmount(1, 50.0);
    system.saveUserAccounts();

    return 0;
}