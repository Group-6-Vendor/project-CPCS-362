// Dylan Drake


// main.cpp

#include <iostream>
#include <cstdlib>                      // For system("clear") or system("cls") to clear the console
#include "expire_tracker.cpp"
#include "add_items.cpp"
#include "delete_items.cpp"
#include "clear_items.cpp"

//using namespace std           // not needed...for now


// Function to handle expired items
void handleExpiredItems(const std::string& machineID) {

    std::vector<VendingMachineItem> expiringItems = expire_tracker(machineID);   // Call the expire_tracker() function

    // Get the current date
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    clearConsole();
    
    std::cout << "Expiring Items within 30 days:" << std::endl;
    
    for (const auto& item : expiringItems) {
        std::cout << "Name: " << item.name << " | Location: " << item.location
                  << " | Expiration Date: " << item.expirationDate << std::endl;
    }

    // Wait for user input before returning to the menu
    std::cout << "\nPress Enter to return to the main menu...";

    std::cin.ignore(); std::cin.get();    
}


int main() {
    int choice;
    std::string machineID;  // Store vending machine #

    do {
        clearConsole();
        // Display the menu
        std::cout << "Vending Machine Management System\n"
                  << "1. Enter Vending Machine ID Number\n"
                  << "2. Add Items\n"
                  << "3. Delete Items\n"
                  << "4. Expired Checker\n"
                  << "5. Clear Expired List\n"
                  << "6. Quit\n\n";

        // If the vending machine number is not set, prompt the user to enter it
        if (machineID.empty()) {
            std::cout << "Enter Vending Machine ID Number: ";
            std::cin >> machineID;
        }

        std::cout << "Current Vending Machine ID: " << machineID << "\n\n";

        // Display additional menu options based on whether a vending machine number is set
        std::cout << "Enter your choice (";
        if (!machineID.empty()) {
            std::cout << "2-6 or ";
        }
        std::cout << "1 to change vending machine): ";

        // Get user input for the menu choice
        std::cin >> choice;

        // Perform actions based on the user's choice
        switch (choice) {
            case 1:
                // Prompt the user to enter the vending machine number
                std::cout << "Enter Vending Machine ID Number: ";
                // User entering number for choice
                std::cin >> machineID;
                break;
            case 2:
                addItems(machineID);
                break;
            case 3:
              deleteItems(machineID);
                 break;
            case 4:
              handleExpiredItems(machineID);
              break;
            case 5:
               clearItems();
                break;
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;

            default:        // If a choice is invalid, this will trigger below!
                std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);   // If "6", then we exit program

    return 0;
}
