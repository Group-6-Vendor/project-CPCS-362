#include <iostream>
#include <string>

class VendingMachine {
private:
    std::string machineID;
    std::string location;
    std::string address;  // Changed from Address to address for consistency
    std::string state;    // Changed from State to state for consistency

public:
    // Constructor
    VendingMachine(const std::string& id, const std::string& loc, const std::string& adr, const std::string& st)
        : machineID(id), location(loc), address(adr), state(st) {}

    // Function to get and display location information
    void displayLocationInfo() const {
        std::cout << "Vending Machine ID: " << machineID << std::endl;
        std::cout << "Location: " << location << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "State: " << state << std::endl;  // Updated from Location to State
    }
};

int main() {
    // Create a vending machine object
    VendingMachine VM1("VM001", "Office Lobby", "1234 Realstreet Ave", "CA");

    // Display location information
    VM1.displayLocationInfo();

    return 0;
}

