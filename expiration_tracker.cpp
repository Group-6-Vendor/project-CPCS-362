// Dylan Drake
// Expiration_tracker.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Function to load data from the file into a map
void loadItemsFromFile(map<string, string>& items) {
    ifstream file("expiration_tracker.txt");            // Store into file for user to read
    if (file.is_open()) {                               // File open here! Remember to close later!!
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(':');
            if (pos != string::npos) 
            {
                string name = line.substr(0, pos);
                string expirationDate = line.substr(pos + 1);
                items[name] = expirationDate;
            }
        }
        file.close();
    }
}

// Function to save the map to the file
void saveItemsToFile(const map<string, string>& items) {
    ofstream file("expiration_tracker.txt");
    if (file.is_open()) {
        for (const auto& item : items) {
            file << item.first << ":" << item.second << "\n";
        }
        file.close();
    }
}

// Function to remove a product by name
void removeProduct(map<string, string>& items, const string& productName) {
    auto it = items.find(productName);
    if (it != items.end()) {
        items.erase(it);
    }
}

int main() {
    map<string, string> items;

    // Load existing data from the file
    loadItemsFromFile(items);

    int choice;

    // Loop until program exits(4) or user CRT+C
    while (true) {
        cout << "Main Menu:\n";
        cout << "1. Check expired items\n";
        cout << "2. Add item expiration date\n";
        cout << "3. Remove product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Check expired items
            cout << "\nStored Items and Expiration Dates:\n";
            for (const auto& item : items) {
                cout << item.first << ": " << item.second << endl;
            }
        } 
        else if (choice == 2) 
        {
            // Add item expiration date
            string name;
            string expirationDate;

            cout << "Please enter the item name: ";
            cin >> name;

            if (name == "9999") {
                break; // Exit the program if "9999" is entered.
            }

            cout << "Please enter the expiration date (YYYY-MM) for this batch: ";
            cin >> expirationDate;

            // Store the item and its expiration date in the map
            items[name] = expirationDate;

            // Display stored items and their expiration dates
            cout << "\nStored Items and Expiration Dates:\n";
            for (const auto& item : items) {
                cout << item.first << ": " << item.second << endl;
            }

            // Save the map to the file
            saveItemsToFile(items);
        } 
        else if (choice == 3) 
        {
            // Remove product
            string productName;
            // Ask user which product to remove
            cout << "Enter the name of the product you want to remove: ";
            // Store name into "productName"
            cin >> productName;

            removeProduct(items, productName);
            saveItemsToFile(items);

            // Let user know product was removed successfully
            cout << "Product '" << productName << "' was successfully removed!\n";
        } else if (choice == 4) 
        {
            break; // Exit the program
        }
         else 
         {
            cout << "Invalid choice. Please select a valid option and try again.\n";
         }
    }

    return 0; // Return 0 for Success!
}
