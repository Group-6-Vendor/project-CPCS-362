// expire_tracker.cpp

#include "expire_tracker.h"

std::vector<VendingMachineItem> expire_tracker(const std::string& machineID) {
    std::vector<VendingMachineItem> expiringItems;

    // Vending machine ID for list
    std::string filename = "vending_machine_list_" + machineID + ".txt";

    // Open the file using machineID
    std::ifstream file(filename);

    //
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        // if file failed to open, return!
        return expiringItems;
    }

    // Get the current date for the machine to operate correctly
    auto now = std::chrono::system_clock::now();
    // make sure this part works before deployment goes live....

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::string line;

    while (std::getline(file, line)) { // get name, slot number, location, date, quantity
        std::istringstream iss(line);
        std::string name, location, date;
        int slotNumber;

        if (std::getline(iss, name, ':') &&
            (iss >> slotNumber) &&
            std::getline(iss, location, ':') &&
            std::getline(iss, date)) {

            std::tm expirationTime = {};
            std::istringstream dateStream(date);
            dateStream >> std::get_time(&expirationTime, "%m-%d-%Y");

            auto expirationPoint = std::chrono::system_clock::from_time_t(std::mktime(&expirationTime));
            auto thirtyDaysLater = now + std::chrono::hours(30 * 24);

            if (expirationPoint <= thirtyDaysLater) {
                // check this!
                expiringItems.push_back({name, slotNumber, location, date, 0}); // Assuming quantity is not needed for expiration tracking
            }
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    // EOF, so we close before leaving
    file.close();

    // return the items that will/are expired!
    return expiringItems;
}
