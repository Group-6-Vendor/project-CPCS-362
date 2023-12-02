#include <iostream>
#include <fstream>
#include <limits> // for numeric_limits

// Function to handle addition tracking
int addition_tracker(int rowCapacity, int UPC, bool isFull, int productRem) {
    int attemptCount = 0;

    std::ofstream logFile("log file.txt", std::ios_base::app); // Append mode

    if (!logFile.is_open()) {
        std::cerr << "Error opening log file.\n";
        return -1;
    }

    if (!isFull) {
        return 0; // Nothing added, return with no change.
    }
    else if (productRem >= rowCapacity) {
        std::cout << "Please stock the item with the barcode: " << UPC
                  << ". Amount to stock = " << (rowCapacity - productRem) << ".\n"
                  << "When you are finished stocking, please enter 'complete'. "
                  << "If there's a problem, enter 'problem'. Thank you!\n";

        while (attemptCount < 5) {
            std::string messageCode;
            std::cin >> messageCode;

            if (messageCode == "complete" || messageCode == "Complete") {
                int stockedQuantity = rowCapacity - productRem;
                logFile << "Successful stock. Barcode: " << UPC << ", Quantity: " << stockedQuantity << '\n';
                return stockedQuantity;
            }
            else if (messageCode == "problem" || messageCode == "Problem") {
                logFile << "Problem encountered while stocking. Barcode: " << UPC << '\n';
                return -1;
            }
            else {
                std::cout << "Unrecognized input. Please try again.\n";
                ++attemptCount;
            }
        }

        std::cerr << "Too many attempts! Exiting program...\n";
        logFile << "Too many unsuccessful attempts. Barcode: " << UPC << '\n';
        assert(false); // This should never be reached; exit with an error.
    }
    else {
        // Machine is full, no more room to fit any more product.
        logFile << "Machine full. No more room for product. Barcode: " << UPC << '\n';
        return 0;
    }

    // Log critical error if this point is reached
    logFile << "A critical error has occurred! 'ERROR! integer not found'.\n"
            << "Please restart the machine. If this issue occurs again, contact your on-duty supervisor for support. Thank you!\n";

    std::cerr << "Critical error! Exiting program...\n";
    logFile.close();
    assert(false); // This should never be reached; exit with an error.
}

int main() {
    // Example usage
    int rowCapacity = 10;
    int UPC = 12345;
    bool isFull = true;
    int productRem = 8;

    int result = addition_tracker(rowCapacity, UPC, isFull, productRem);

    if (result > 0) {
        std::cout << "Successfully stocked " << result << " items.\n";
    } else if (result == 0) {
        std::cout << "No items added.\n";
    } else {
        std::cerr << "Stocking failed or encountered a problem.\n";
    }

    return 0;
}
