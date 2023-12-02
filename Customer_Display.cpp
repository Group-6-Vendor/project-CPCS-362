#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

class Product {
public:
    Product(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    // ... (unchanged)

    double calculateTotalPrice(int quantity) const {
        return quantity * price;
    }
};

void displayProducts(const std::vector<Product>& products) {
    std::cout << "Available Products:" << std::endl;
    for (std::size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i] << std::endl;
    }
}

int main() {
    std::vector<Product> products = {
        Product("Coke", 0.50, 10),
        Product("Lay's", 0.30, 10),
        Product("Coffee", 2.00, 10),
        Product("Sneakers", 1.50, 10),
    };

    while (true) {
        try {
            displayProducts(products);

            int choice;
            std::cout << "Select a product number to purchase or enter 0 to exit: ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            if (choice == 0) {
                break;
            }

            if (choice > 0 && choice <= static_cast<int>(products.size())) {
                Product& selectedProduct = products[choice - 1];

                std::cout << "You have selected: " << selectedProduct << std::endl;

                int qty;
                std::cout << "Enter the quantity to purchase: ";
                std::cin >> qty;

                if (std::cin.fail()) {
                    throw std::invalid_argument("Invalid input. Please enter a number.");
                }

                if (qty > 0) {
                    if (qty <= selectedProduct.getQuantity()) {
                        double total_price = selectedProduct.calculateTotalPrice(qty);
                        selectedProduct.setQuantity(selectedProduct.getQuantity() - qty);

                        std::cout << "You purchased " << qty << " " << selectedProduct.getName()
                                  << "(s) for $" << std::fixed << std::setprecision(2) << total_price << std::endl;
                    } else {
                        std::cout << "We only have " << selectedProduct.getQuantity() << " "
                                  << selectedProduct.getName() << "(s) available." << std::endl;
                    }
                } else {
                    std::cout << "Invalid quantity. Please enter a positive number." << std::endl;
                }
            } else {
                std::cout << "Invalid choice. Please select a valid product number." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
