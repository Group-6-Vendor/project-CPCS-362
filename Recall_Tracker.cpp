#include <iostream>
#include <string>
#include <vector>

// Structure to represent a recall request
struct RecallRequest {
    int requestID;
    std::string itemName;
    std::string reason;
};

// Vector to store recall requests
std::vector<RecallRequest> recallRequests;

// Function to record a recall request
void RecordRecallRequest() {
    RecallRequest request;
    
    // Simulate requesting input from the manager
    std::cout << "Enter Recall Request ID: ";
    std::cin >> request.requestID;
    std::cin.ignore(); // Clear the newline character
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, request.itemName);
    std::cout << "Enter Recall Reason: ";
    std::getline(std::cin, request.reason);
    
    // Add the request to the vector
    recallRequests.push_back(request);
    
    // Notify customers (not implemented here)
    std::cout << "Recall request recorded. Notifying customers." << std::endl;
}

// Function to generate restock instructions
void GenerateRestockInstructions() {
    std::cout << "Restock Instructions:\n";
    
    for (const RecallRequest& request : recallRequests) {
        std::cout << "Replace item '" << request.itemName << "' (Recall Request ID: " << request.requestID << ") due to recall.\n";
    }
    
    std::cout << "Please restock the above items promptly.\n";
}

int main() {
    char choice;
    
    do {
        std::cout << "Recall Tracker Menu:\n";
        std::cout << "1. Record Recall Request\n";
        std::cout << "2. Generate Restock Instructions\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case '1':
                RecordRecallRequest();
                break;
            case '2':
                GenerateRestockInstructions();
                break;
            case '3':
                std::cout << "Exiting Recall Tracker.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');
    
    return 0;
}
