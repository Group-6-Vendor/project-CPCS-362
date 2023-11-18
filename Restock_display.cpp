#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Addition Tracker class
class AdditionTracker {
public:
    std::vector<std::pair<std::string, int>> additions;

    void track_addition(const std::string& item, int quantity) {
        additions.push_back(std::make_pair(item, quantity));
    }
};

// Expiration Tracker class
class ExpirationTracker {
public:
    std::vector<std::pair<std::string, std::string>> expirations;

    void track_expiration(const std::string& item, const std::string& expiration_date) {
        expirations.push_back(std::make_pair(item, expiration_date));
    }
};

// Slot Tracker class
class SlotTracker {
public:
    std::unordered_map<std::string, int> slots;

    void track_slot(const std::string& item, int slot_number) {
        slots[item] = slot_number;
    }
};

// Purchase Tracker class
class PurchaseTracker {
public:
    std::vector<std::pair<std::string, int>> purchases;

    void track_purchase(const std::string& item, int quantity) {
        purchases.push_back(std::make_pair(item, quantity));
    }
};

int main() {
    // Create instances of each tracker
    AdditionTracker addition_tracker;
    ExpirationTracker expiration_tracker;
    SlotTracker slot_tracker;
    PurchaseTracker purchase_tracker;

    // Created sample data for the trackers to show that it works
    addition_tracker.track_addition("Item A", 10);
    expiration_tracker.track_expiration("Item A", "2023-10-31");
    slot_tracker.track_slot("Item A", 5);
    purchase_tracker.track_purchase("Item A", 5);

    // Display relevant tracked information to restockers
    std::cout << "Additions:" << std::endl;
    for (const auto& addition : addition_tracker.additions) {
        std::cout << addition.first << ": " << addition.second << " added" << std::endl;
    }

    std::cout << "\nExpirations:" << std::endl;
    for (const auto& expiration : expiration_tracker.expirations) {
        std::cout << expiration.first << ": Expires on " << expiration.second << std::endl;
    }

    std::cout << "\nSlots:" << std::endl;
    for (const auto& slot : slot_tracker.slots) {
        std::cout << slot.first << " is in slot " << slot.second << std::endl;
    }

    std::cout << "\nPurchases:" << std::endl;
    for (const auto& purchase : purchase_tracker.purchases) {
        std::cout << purchase.first << ": " << purchase.second << " purchased" << std::endl;
    }

    return 0;
}
