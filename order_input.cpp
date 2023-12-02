#include <iostream>
#include <map>
#include <ctime>

class ItemScanner {
public:
    static std::map<std::string, std::map<std::string, std::string>> inventory;
};

bool expired(const std::string& expiration_date) {
    std::time_t today_time = std::time(nullptr);
    std::tm* today = std::localtime(&today_time);

    std::tm exp_date = {};
    std::istringstream(expiration_date) >> std::get_time(&exp_date, "%Y-%m-%d");

    return std::mktime(today) > std::mktime(&exp_date);
}

std::pair<std::string, std::string> getItem(int selected_item) {
    std::map<std::string, std::map<std::string, std::string>> items = ItemScanner::inventory;

    if (selected_item >= 1 && selected_item <= items.size()) {
        auto it = items.begin();
        std::advance(it, selected_item - 1);

        const std::string& item_name = it->first;
        const std::string& expiration_date = it->second["expiration_date"];

        return std::make_pair(item_name, expiration_date);
    } else {
        return std::make_pair("", "");
    }
}

void purchase(const std::string& item_name) {
    std::map<std::string, std::map<std::string, std::string>>& inventory = ItemScanner::inventory;

    if (inventory.find(item_name) != inventory.end() && std::stoi(inventory[item_name]["quantity"]) > 0) {
        std::cout << "Purchase of one " << item_name << " confirmed." << std::endl;
        inventory[item_name]["quantity"] = std::to_string(std::stoi(inventory[item_name]["quantity"]) - 1);
    } else {
        std::cout << "This item is out of stock." << std::endl;
    }
}

int main() {
    while (true) {
        try {
            int selected_item;
            std::cout << "Enter the number of your selection (1-40) (use 0 to quit): ";
            std::cin >> selected_item;

            if (selected_item == 0) {
                break;
            }

            auto selection = getItem(selected_item);
            if (!selection.first.empty()) {
                const std::string& item_name = selection.first;
                const std::string& expiration_date = selection.second;

                std::cout << "You have selected: " << item_name << std::endl;

                if (expired(expiration_date)) {
                    std::cout << "This item is expired." << std::endl;
                } else {
                    char confirm;
                    std::cout << "Would you like to purchase this item (y or n)? ";
                    std::cin >> confirm;

                    if (confirm == 'n') {
                        std::cout << "Purchase cancelled." << std::endl;
                    } else if (confirm == 'y') {
                        purchase(item_name);
                    } else {
                        std::cout << "Invalid answer." << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid selection." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Invalid input." << std::endl;
        }
    }

    return 0;
}
