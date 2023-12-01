// clear_items.cpp

#include <iostream>
#include "expire_tracker.h"


static void clearConsole2() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void clearItems() {
    clearConsole2();
    std::cout << "Option 5: Clear Items\n";
    std::string machineID;

    std::cout << "Enter Vending Machine ID Number: ";
    std::cin >> machineID;
    // making sure to check with machine it is clearing first!
    
    std::string filename = "vending_machine_list_" + machineID + ".txt";
    
    std::ifstream inputFile(filename);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Display a warning message
    std::cout << "Warning: This will clear the entire list for machine " << machineID << ".\n";
    std::cout << "Are you sure about this? Type 'Yes' or 'No' to confirm your decision: ";
    
    // Get a user confirmation first
    std::string confirmation;
    std::cin >> confirmation;

// We are good to go throught with it!
    if (confirmation == "Yes" || confirmation == "yes") {
        
        // Close file
        inputFile.close();
        
        // Open the file in write mode to truncate//
        std::ofstream outputFile(filename, std::ios::trunc);
        
        
        // Check if the file is open
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }  // if this fails again, reconsider using older format...

        // Close the output file
        outputFile.close();
        std::cout << "List cleared successfully!\n";
    } 
    else {
        std::cout << "Clear operation aborted.\n";
    }

    // Wait for user input before returning to the main menu
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get();
}
