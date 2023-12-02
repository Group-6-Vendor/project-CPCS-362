#include <iostream>
#include <string>
#include <map>
#include <ctime>

class Product {
public:
    std::string id;
    std::string name;
    std::time_t expiryDate;

    Product(const std::string& id, const std::string& name, std::time_t expiryDate)
        : id(id), name(name), expiryDate(expiryDate) {}
};

class PurchaseTracker {
private:
    std::map<std::string, Product> products;
    std::map<std::string, int> monthlySales;
    std::map<std::string, int> yearlySales;
    std::time_t currentTime;

public:
    PurchaseTracker() {
        currentTime = std::time(nullptr);
    }

    void addProduct(const Product& product) {
        products[product.id] = product;
    }

    void recordPurchase(const std::string& productId) {
        struct tm *ltm = localtime(&currentTime);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;

        std::string monthYearKey = productId + "_" + std::to_string(year) + "_" + std::to_string(month);
        monthlySales[monthYearKey]++;
        yearlySales[productId + "_" + std::to_string(year)]++;
    }

    bool shouldRemoveProduct(const std::string& productId) {
        Product product = products[productId];
        std::time_t now = std::time(nullptr);
        double secondsToExpiry = difftime(product.expiryDate, now);

        if (secondsToExpiry < 604800) { // less than 7 days to expiry
            struct tm *ltm = localtime(&now);
            int year = 1900 + ltm->tm_year;
            int month = 1 + ltm->tm_mon;
            std::string monthYearKey = productId + "_" + std::to_string(year) + "_" + std::to_string(month);

            if (monthlySales[monthYearKey] < 5) { // low purchase frequency
                return true; // remove product
            }
        }
        return false; // do not remove product
    }
};

int main() {
    PurchaseTracker tracker;

    // Example Product with expiry date set to a week from now
    std::time_t nextWeek = std::time(nullptr) + 604800;
    tracker.addProduct(Product("001", "Chips", nextWeek));

    // Simulate purchases
    tracker.recordPurchase("001");
    tracker.recordPurchase("001");

    // Check if product should be removed
    bool shouldRemove = tracker.shouldRemoveProduct("001");
    std::cout << "Should remove product '001': " << (shouldRemove ? "Yes" : "No") << std::endl;

    return 0;
}
