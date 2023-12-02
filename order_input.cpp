#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <chrono>

// Forward declaration
class ItemScanner;

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> inventory;

class ItemScanner {
public:
    static bool expired(const std::string& expirationDate) {
        auto today = std::chrono::system_clock::now();
        auto expDate = parseDate(expirationDate);
        return expDate < today;
    }

    static std::pair<std::string, std::string> getItem(int selectedItem) {
        std::vector<std::string> items;
        for (const auto& item : inventory) {
            items.push_back(item.first);
        }

        if (selectedItem >= 1 && selectedItem <= static_cast<int>(items.size())) {
            const std::string& itemName = items[selectedItem - 1];
            const std::string& expirationDate = inventory[itemName]["expiration_date"];
            return std::make_pair(itemName, expirationDate);
        } else {
            return std::make_pair("", "");
        }
    }

    static void purchase(const std::string& itemName) {
        if (inventory.find(itemName) != inventory.end() && inventory[itemName]["quantity"] > 0) {
            std::cout << "Purchase of one " << itemName << " confirmed." << std::endl;
            inventory[itemName]["quantity"] -= 1;
        } else {
            std::cout << "This item is out of stock." << std::endl;
        }
    }

private:
    static std::chrono::system_clock::time_point parseDate(const std::string& date) {
        std::tm tm = {};
        std::istringstream ss(date);
        ss >> std::get_time(&tm, "%Y-%m-%d");
        auto time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        return time;
    }
};

int main() {
    while (true) {
        try {
            int selected_item;
            std::cout << "Enter the number of your selection (1-40) (use 0 to quit): ";
            std::cin >> selected_item;

            if (selected_item == 0) {
                break;
            }

            auto selection = ItemScanner::getItem(selected_item);

            if (!selection.first.empty()) {
                const std::string& itemName = selection.first;
                const std::string& expirationDate = selection.second;

                std::cout << "You have selected: " << itemName << std::endl;

                if (ItemScanner::expired(expirationDate)) {
                    std::cout << "This item is expired." << std::endl;
                } else {
                    char confirm;
                    std::cout << "Would you like to purchase this item (y or n)? ";
                    std::cin >> confirm;

                    if (confirm == 'n') {
                        std::cout << "Purchase cancelled." << std::endl;
                    } else if (confirm == 'y') {
                        ItemScanner::purchase(itemName);
                    } else {
                        std::cout << "Invalid answer." << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid selection." << std::endl;
            }
        } catch (...) {
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
