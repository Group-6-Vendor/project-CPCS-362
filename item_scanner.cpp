#include <iostream>
#include <iomanip>
#include <map>

std::map<std::string, std::map<std::string, std::string>> inventory;

void addItem(const std::string& name, int quantity, const std::string& expirationDate, int slot) {
    if (inventory.find(name) == inventory.end()) {
        inventory[name] = {
            {"quantity", "0"},
            {"expirationDate", ""},
            {"slot", "0"}
        };
    }

    inventory[name]["quantity"] = std::to_string(std::stoi(inventory[name]["quantity"]) + quantity);
    inventory[name]["expirationDate"] = expirationDate;
    inventory[name]["slot"] = std::to_string(slot);
}

void displayInventory() {
    std::cout << "Current Inventory:" << std::endl;
    for (const auto& [name, itemInfo] : inventory) {
        int totalQuantity = std::stoi(itemInfo.at("quantity"));
        std::string expirationDate = itemInfo.at("expirationDate");
        std::string slot = itemInfo.at("slot");
        std::cout << name << ": " << totalQuantity << " items, Expiration Date: " << expirationDate
                  << ", Slot: " << slot << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "\nStock Item (or type 'quit' to exit):" << std::endl;

        std::string name;
        std::cout << "Enter item name: ";
        std::getline(std::cin, name);
        name.erase(name.find_last_not_of(" \n\r\t") + 1);

        if (name == "quit") {
            break;
        }

        try {
            int quantity;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            std::string expirationDate;
            std::cout << "Enter expiration date (YYYY-MM-DD): ";
            std::cin >> expirationDate;

            int slot;
            std::cout << "Enter slot: ";
            std::cin >> slot;

            addItem(name, quantity, expirationDate, slot);
            std::cout << quantity << " " << name << " added to inventory in slot " << slot << "." << std::endl;
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid quantity." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    displayInventory();

    return 0;
}
