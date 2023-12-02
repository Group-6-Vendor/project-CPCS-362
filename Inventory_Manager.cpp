#include <iostream>
#include <unordered_map>
#include <string>

class Product {
public:
    std::string id;
    std::string name;
    double price;
    int quantity;

    Product(std::string id, std::string name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}
};

class InventorySlot {
public:
    Product product;
    int slotNumber;

    InventorySlot(Product product, int slotNumber)
        : product(product), slotNumber(slotNumber) {}
};

class InventoryManager {
private:
    std::unordered_map<int, InventorySlot> slots;

public:
    void updateProductInSlot(int slotNumber, Product product) {
        auto it = slots.find(slotNumber);
        if (it != slots.end()) {
            it->second.product = product;
        } else {
            std::cerr << "Slot number " << slotNumber << " does not exist." << std::endl;
        }
    }

    void changeProductQuantity(int slotNumber, int newQuantity) {
        auto it = slots.find(slotNumber);
        if (it != slots.end()) {
            it->second.product.quantity = newQuantity;
        } else {
            std::cerr << "Slot number " << slotNumber << " does not exist." << std::endl;
        }
    }

    void addSlot(int slotNumber, Product product) {
        if (slots.find(slotNumber) == slots.end()) {
            slots[slotNumber] = InventorySlot(product, slotNumber);
        } else {
            std::cerr << "Slot number " << slotNumber << " already exists." << std::endl;
        }
    }

    void removeSlot(int slotNumber) {
        auto it = slots.find(slotNumber);
        if (it != slots.end()) {
            slots.erase(it);
        } else {
            std::cerr << "Slot number " << slotNumber << " does not exist." << std::endl;
        }
    }

    void displayInventory() const {
        std::cout << "Current Inventory:\n";
        for (const auto& entry : slots) {
            const InventorySlot& slot = entry.second;
            const Product& product = slot.product;
            std::cout << "Slot " << slot.slotNumber << ": " << product.name
                      << ", Quantity: " << product.quantity << ", Price: $" << product.price << "\n";
        }
        std::cout << "-------------------\n";
    }
};

class VendingMachine {
private:
    InventoryManager inventoryManager;

public:
    void restock(int slotNumber, Product product, int quantity) {
        inventoryManager.updateProductInSlot(slotNumber, product);
        inventoryManager.changeProductQuantity(slotNumber, quantity);
        // Display updated restock list or changes to the stocker
    }

    // ... Other vending machine functionalities
};

int main() {
    VendingMachine vendingMachine;

    // Stockers would call these methods to update the inventory
    Product cola("001", "Cola", 1.25, 10);
    vendingMachine.restock(1, cola, 10);

    // Display current inventory
    vendingMachine.displayInventory();

    // ... Other operations

    return 0;
}
