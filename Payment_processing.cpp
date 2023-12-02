#include <iostream>

// Function to insert money in cash and coins
void insertMoney(float& customerPayment) {
    while (true) {
        try {
            float money;
            std::cout << "Insert money or coins (enter 0 to finish): $";
            std::cin >> money;

            if (money == 0) {
                break;
            }

            customerPayment += money;
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid amount." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    // Get the total price of the selected item
    float totalPrice;
    std::cout << "Enter the total price: $";
    std::cin >> totalPrice;

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

    return 0;
}
