// add_items.cpp

#include <iostream>

#include "add_items.h"
#include "expire_tracker.h"  

// To clear the console/terminal

static void clearConsole1() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Function to add items
void addItems(const std::string& machineID) {
 
 
    clearConsole1();

    std::cout << "Option 2: Add Items\n";

    // Prompt the user for item details
    std::string name, location, date;
    
    std::cout << "Enter item details in the format (Name:Location:MM-DD-YYYY):" << std::endl;           // need to add slotNumber before location!
    
    std::cout << "Name: ";
    
    std::cin.ignore(); 
    // ignore 
    
    std::getline(std::cin, name);

    std::cout << "Location (Number and Letter): ";
    std::getline(std::cin, location);

    std::cout << "Expiration Date (MM-DD-YYYY, or press the 'Enter' key for 12-31-2055 (default date for non-expirable items). ): ";
    std::getline(std::cin, date);

    // If the user did not provide an expiration date, set it to 12-31-2055
    if (date.empty()) {
        date = "12-31-2055";
    }


    std::string filename = "vending_machine_list_" + machineID + ".txt";        // If name file don't exist, create filename for text


    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "!" << std::endl;
        // If file does not exist, error and return function.
        return;
    }


    // File format for storing item expiration date, name and location
    file << name << ":" << location << ":" << date << "\n";

    file.close();           // Close file before leaving

    std::cout << "Item added successfully!\n";

    std::cout << "Press 'Enter' to return to the main menu...";

    std::cin.ignore();  // Ignore char input once
    std::cin.get();    
    // Function finishes
}