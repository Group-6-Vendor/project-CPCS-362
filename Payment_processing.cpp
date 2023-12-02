#include <iostream>
#include <iomanip>

// Function to insert money in cash and coins
void insertMoney(float &customerPayment) {
    while (true) {
        try {
            float money;
            std::cout << "Insert money or coins (enter 0 to finish): $";
            std::cin >> money;

            if (money == 0) {
                break;
            }

            if (money < 0) {
                throw std::invalid_argument("Amount cannot be negative.");
            }

            customerPayment += money;
        } catch (const std::exception &e) {
            std::cerr << "Invalid input: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    try {
        // Get the total price of the selected item
        float totalPrice;
        std::cout << "Enter the total price: $";
        std::cin >> totalPrice;

        if (totalPrice < 0) {
            throw std::invalid_argument("Total price cannot be negative.");
        }

        // Initialize variables for the customer's payment and change
        float customerPayment = 0.0;

        // Get the customer's payment in cash and coins
        std::cout << "Insert cash and coins to pay for the item:" << std::endl;
        insertMoney(customerPayment);

        // Calculate the change and provide the receipt
        while (customerPayment < totalPrice) {
            std::cout << "Remaining balance: $" << std::fixed << std::setprecision(2) << totalPrice - customerPayment << std::endl;
            std::cout << "Insufficient payment. Please provide more cash and coins." << std::endl;
            insertMoney(customerPayment);
        }

        float change = customerPayment - totalPrice;

        std::cout << "Thank you for your purchase!" << std::endl;
        std::cout << "Total price: $" << std::fixed << std::setprecision(2) << totalPrice << std::endl;
        std::cout << "Customer payment: $" << std::fixed << std::setprecision(2) << customerPayment << std::endl;
        std::cout << "Change: $" << std::fixed << std::setprecision(2) << change << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
