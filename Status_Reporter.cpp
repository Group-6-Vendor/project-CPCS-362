#include <iostream>
#include <map>
#include <string>
#include <sstream>

class VendingMachine {
public:
    VendingMachine(const std::string& sender_email, const std::string& sender_password)
        : sender_email(sender_email), sender_password(sender_password) {
        // Initialize the vending machine with some items and stock levels
        items = {
            {"Item A", 10},
            {"Item B", 8},
            {"Item C", 15},
        };
    }

    void sendStatusReport(const std::string& manager_email, const std::string& subject, const std::string& message) {
        // Simulate sending an email by printing to the console
        std::cout << "Sending email to: " << manager_email << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Message: " << message << std::endl;
    }

    void reportStatus(const std::string& manager_email) {
        // Generate a status report message
        std::stringstream status_report;
        status_report << "Vending Machine Status Report:\n\n";
        for (const auto& [item, stock] : items) {
            status_report << item << ": " << stock << " available\n";
        }

        // Send the status report via email
        std::string subject = "Vending Machine Status Report";
        sendStatusReport(manager_email, subject, status_report.str());
    }

    void restockItem(const std::string& item, int quantity) {
        // Restock a specific item with the given quantity
        auto it = items.find(item);
        if (it != items.end()) {
            it->second += quantity;
        } else {
            std::cout << "Item needs to be restocked in the vending machine." << std::endl;
        }
    }

private:
    std::string sender_email;
    std::string sender_password;
    std::map<std::string, int> items;
};

int main() {
    // Replace with your email and password
    std::string sender_email = "your_email_address";
    std::string sender_password = "your_password";

    VendingMachine vending_machine(sender_email, sender_password);
    std::string manager_email = "manager_email_address";  // Replace with the manager's email

    // Report the initial status
    vending_machine.reportStatus(manager_email);

    // Restock an item (e.g., Item A with 5 more units)
    vending_machine.restockItem("Item A", 5);

    // Report the updated status
    vending_machine.reportStatus(manager_email);

    return 0;
}
