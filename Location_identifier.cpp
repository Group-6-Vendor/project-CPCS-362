#include <iostream>
#include <string> 

class VendingMachine {
private:
    std::string machineID;
    std::string location;
    std::string Address;
    std::string State;

public:
    // Constructor
    VendingMachine(const std::string& id, const std::string& loc, const std::string& adr, const std::string& st)
        : machineID(id), location(loc), Address(adr), State(st) {}

    // Function to get and display location information
    void displayLocationInfo() const {
        std::cout << "Vending Machine ID: " << machineID << std::endl;
        std::cout << "Location: " << location << std::endl;
        std::cout << "Address: " << Address << std::endl;
        std::cout << "Location: " << State << std::endl;
    }

};

int main() {
    // Create a vending machine object
    VendingMachine VM1("VM001", "Office Lobby", "1234 Realstreet Ave", "CA");

    // Display location information
    VM1.displayLocationInfo();

    return 0;
}