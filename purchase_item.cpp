// purchase_item.cpp

#include "purchase_item.h"

std::vector<VendingMachineItem> getInventory(const std::string& machineID) {
    std::vector<VendingMachineItem> inventory;

    std::string filename = "vending_machine_list_" + machineID + ".txt";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return inventory;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        VendingMachineItem item;

        if (std::getline(iss, item.name, ':') &&
            (iss >> item.slotNumber) &&
            std::getline(iss, item.location, ':') &&
            std::getline(iss, item.expirationDate, ':') &&
            (iss >> item.quantity)) {
            inventory.push_back(item);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    return inventory;
}

void updateInventory(const std::string& machineID, const std::vector<VendingMachineItem>& inventory) {
    std::string filename = "vending_machine_list_" + machineID + ".txt";
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& item : inventory) {
        file << item.name << ':' << item.slotNumber << ':' << item.location << ':' << item.expirationDate << ':' << item.quantity << '\n';
    }

    file.close();
}

bool isItemExpired(const VendingMachineItem& item) {
    // Get the current date
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Parse the expiration date of the item
    std::tm expirationTime = {};
    std::istringstream dateStream(item.expirationDate);
    dateStream >> std::get_time(&expirationTime, "%m-%d-%Y");


    auto expirationPoint = std::chrono::system_clock::from_time_t(std::mktime(&expirationTime));

    // Check if the item is expired
    return expirationPoint <= now;
}

void purchaseItem(const std::string& machineID) {
    // Assuming you have a function in item_scanner to get the inventory
    std::vector<VendingMachineItem> inventory = getInventory(machineID);

    // Prompt the user to enter the slot and location
    std::cout << "Enter the slot and location of the item you would like to purchase (e.g., 3A): ";
    std::string input;
    std::cin >> input;

    // Validate the input format (e.g. "3A")
    if (input.size() < 2 || !std::isdigit(input[0]) || !std::isalpha(input[1])) {
        std::cout << "Invalid input format. Please enter a valid combination of a number and a letter (e.g., 3A).\n";
        return;
    }

int slotNumber = std::stoi(input.substr(0, 1)); 
char location = std::toupper(input[1]);         

// Debug
std::cout << "Debugging: Slot Number = " << slotNumber << ", Location = " << location << std::endl;

// Check if the slot number is valid
if (slotNumber >= 1 && slotNumber <= inventory.size()) {

    // Check if the selected item is expired
    if (isItemExpired(inventory[slotNumber - 1])) {
        std::cout << "Selected item is expired. Cannot proceed with the purchase.\n";
    } else {
       
        // Convert the location in inventory to uppercase for comparison
        std::string inventoryLocation = inventory[slotNumber - 1].location;
        std::transform(inventoryLocation.begin(), inventoryLocation.end(), inventoryLocation.begin(), ::toupper);

        // Convert the user input location to uppercase for comparison
        char userLocation = std::toupper(location);

        // Debugging output
        std::cout << "Debugging: Inventory Location = " << inventoryLocation << ". " << std::endl;

        // Check if the item is in stock and the location matches (case-insensitive)
        if (inventory[slotNumber - 1].quantity > 0 && inventoryLocation[0] == userLocation) {
            // Reduce the quantity of the selected item by one
            inventory[slotNumber - 1].quantity--;

            // Update the inventory in item_scanner
            updateInventory(machineID, inventory);

            // Inform the user about the successful purchase they made
            std::cout << "Purchase successful! You bought: " << inventory[slotNumber - 1].name << "\n";
        } else {
            std::cout << "Invalid location or selected item is out of stock. Cannot proceed with the purchase.\n";
        }
    }
} else {
    std::cout << "Invalid slot number. Please enter a number between 1 and " << inventory.size() << ".\n";
}
}// EOF