// main.cpp

#include <iostream>
#include <cstring>
#include <iomanip>

#include "add_items.h"
#include "delete_items.h"
#include "clear_items.h"
#include "expire_tracker.h"
#include "purchase_item.h"


static void clearConsole() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}


int main() {
    int choice;
    std::string machineID;  // Store the vending machine number here

    do {
       // clearConsole();     // clear any previous output before displaying the menu
        // Display the menu
        std::cout << "Vending Machine Management System\n"
                  << "1. Enter Vending Machine ID Number\n"
                  << "2. Add Items\n"
                  << "3. Delete Items\n"
                  << "4. Expired Checker\n"
                  << "5. Clear Expired List\n"
                  << "6. Purchase Item\n"
                  << "7. Quit\n\n";

        // If the vending machine number is not set, prompt the user to enter it
        if (machineID.empty()) {
            std::cout << "Enter Vending Machine ID Number: ";
            std::cin >> machineID;
        }

        std::cout << "Current Vending Machine ID: " << machineID << "\n\n";

        // Display additional menu options based on whether a vending machine number is set
        // Consider additional methods of implementation here or QOL
        std::cout << "Enter your choice (";
        if (!machineID.empty() ) 
        {
            std::cout << "2-6 or ";
        }

        std::cout << "1 to change vending machine): ";
        // Stay on this line for user to clearly see choice...


        // Get user input for the menu choice
        std::cin >> choice;

        
    std::vector<VendingMachineItem> expiredItems = expire_tracker(machineID);
        // Perform actions based on the user's choice
        switch (choice) {
            case 1:
                // Prompt the user to enter the vending machine number
                std::cout << "Enter Vending Machine ID Number: ";
                std::cin >> machineID;
                break;
            case 2:
                addItems(machineID);
                break;
            case 3:
                deleteItems(machineID);
                break;
            case 4:
              expiredItems = expire_tracker(machineID);
                // Process the expired items as needed
                for (const auto& item : expiredItems) {
                    std::cout << "Expired Item: " << item.name << " at " << item.location << " on " << item.expirationDate << "\n";
                }
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            case 5:
                clearItems();
                break;
            case 6:
                purchaseItem(machineID);
                break;
            case 7:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 7);

    return 0;
}