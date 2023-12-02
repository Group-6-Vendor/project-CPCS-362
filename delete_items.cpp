// delete_items.cpp

#include <iostream>
#include "expire_tracker.h"

static  void clearConsole3() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void deleteItems(const std::string& machineID) {
    clearConsole3();
    std::cout << "Option 3: Delete Items\n";
    // Construct the filename based on the machineID
    std::string filename = "vending_machine_list_" + machineID + ".txt";
    // Open the file in read mode
    std::ifstream inputFile(filename);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Create temporary file for writing
    std::string tempFilename = "temp_" + filename;
    std::ofstream tempFile(tempFilename);

    // Check if temporary file is open
    if (!tempFile.is_open()) {
        std::cerr << "Error opening temporary file: " << tempFilename << std::endl;
        inputFile.close();
        return;
    }

    // Ask user the name of the item they wish to delete
    std::string itemToDelete;
    std::cout << "Enter the Name of the item to delete: ";
    std::cin.ignore();
    std::getline(std::cin, itemToDelete);

    // Check if item is found or deleted
    bool itemFound = false;
    // Read the original file
    std::string line;

    // Check if the line contains the item to delete. If not, write the line to the temporary file
    while (std::getline(inputFile, line)) {
        if (line.find(itemToDelete) == std::string::npos) {
            tempFile << line << "\n";
        } else {
            itemFound = true;
        }
    }

    // Close the files
    inputFile.close();
    tempFile.close();

    // Remove the original file
    std::remove(filename.c_str());
    // Rename the temporary file to the original file name
    std::rename(tempFilename.c_str(), filename.c_str());

    // Display whether the item was deleted or not found
    if (itemFound) {
        std::cout << "Item '" << itemToDelete << "' deleted successfully!\n";
    } else {
        std::cout << "Item '" << itemToDelete << "' not found!\n";
    }

    // Wait for user input before returning to the main menu
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get();
}