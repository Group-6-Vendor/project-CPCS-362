#include <iostream>
#include <map>

class VendingMachine {
private:
    std::map<std::string, int> inventory;  // Item name and quantity
    std::map<std::string, double> prices;   // Item name and price

public:
    // Constructor to initialize the vending machine
    VendingMachine(std::map<std::string, int> initialInventory, std::map<std::string, double> initialPrices) {
        inventory = initialInventory;
        prices = initialPrices;
    }


    // Display the current inventory and prices
    void displayStatistics() const {
        std::cout << "Current Statistics:\n";
        std::cout << "-------------------\n";
        for (const auto& item : inventory) {
            std::cout << "Item: " << item.first << "\tQuantity: " << item.second << "\tPrice: $" << prices[item.first] << "\n";
        }
        std::cout << "-------------------\n";
    }

    // Simulate a purchase
    bool purchaseItem(const std::string& itemName, double amountPaid) {
        if (inventory.find(itemName) != inventory.end() && inventory[itemName] > 0 && amountPaid >= prices[itemName]) {
            std::cout << "Dispensing " << itemName << ". Thank you for your purchase!\n";
            inventory[itemName]--;
            return true;
        } else {
            std::cout << "Failed to purchase " << itemName << ". Insufficient quantity or funds.\n";
            return false;
        }
    }
};

int main() {
    // Initial inventory and prices
    std::map<std::string, int> initialInventory = {{"Soda", 10}, {"Chips", 15}, {"Chocolate", 20}};
    std::map<std::string, double> initialPrices = {{"Soda", 1.50}, {"Chips", 1.00}, {"Chocolate", 2.00}};

    // Create a vending machine instance
    VendingMachine vendingMachine(initialInventory, initialPrices);

    // Display initial statistics
    vendingMachine.displayStatistics();

    // Simulate some purchases
    vendingMachine.purchaseItem("Soda", 2.00);
    vendingMachine.purchaseItem("Chips", 0.75);

    // Display updated statistics
    vendingMachine.displayStatistics();

    return 0;
}
