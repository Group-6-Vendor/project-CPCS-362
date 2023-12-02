#include <iostream>
#include <vector>
#include <limits>

class Product {
public:
    Product(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        return os << product.name << " - $" << std::fixed << std::setprecision(2) << product.price
                  << " - " << product.quantity << " available";
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

private:
    std::string name;
    double price;
    int quantity;
};

void displayProducts(const std::vector<Product>& products) {
    std::cout << "Available Products:" << std::endl;
    for (std::size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i] << std::endl;
    }

    try {
        std::cout << "Select a product number to purchase or enter 0 to exit: ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Please enter a number.");
        }

        if (choice == 0) {
            throw std::runtime_error("Exit chosen");
        }

        if (choice > 0 && choice <= static_cast<int>(products.size())) {
            std::cout << "Selected product: " << products[choice - 1] << std::endl;
        } else {
            std::cout << "Invalid choice. Please select a valid product number." << std::endl;
            displayProducts(products);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        displayProducts(products);
    }
}

int main() {
    // Sample products
    std::vector<Product> products = {
        Product("Coke", 0.50, 10),
        Product("Lay's", 0.30, 10),
        Product("Coffee", 2.00, 10),
        Product("Sneakers", 1.50, 10),
    };

    while (true) {
        try {
            displayProducts(products);

            int qty;
            std::cout << "Enter the quantity to purchase: ";
            std::cin >> qty;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            Product& selectedProduct = products[0];  // Replace with the actual selected product logic

            if (qty <= selectedProduct.getQuantity()) {
                double total_price = qty * selectedProduct.getPrice();
                selectedProduct.setQuantity(selectedProduct.getQuantity() - qty);
                std::cout << "You purchased " << qty << " " << selectedProduct.getName()
                          << "(s) for $" << std::fixed << std::setprecision(2) << total_price << std::endl;
            } else {
                std::cout << "We only have " << selectedProduct.getQuantity() << " "
                          << selectedProduct.getName() << "(s) available." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
