#include <iostream>
#include <vector>

class SlotTracker {
public:
    SlotTracker(int numSlots, int maxCapacity) : numSlots(numSlots), maxCapacity(maxCapacity) {
        itemsInSlots.resize(numSlots, 0);
    }

    // Track the number of items in a specific slot
    void TrackItemInSlot(int slot, int numItems) {
        if (slot >= 0 && slot < numSlots) {
            itemsInSlots[slot] += numItems;
            CheckOverload();
        }
    }

    // Determine which slots need to be filled
    std::vector<int> GetEmptySlots() {
        std::vector<int> emptySlots;
        for (int i = 0; i < numSlots; i++) {
            if (itemsInSlots[i] < maxCapacity) {
                emptySlots.push_back(i);
            }
        }
        return emptySlots;
    }

    // Check if the machine is overloaded
    void CheckOverload() {
        for (int i = 0; i < numSlots; i++) {
            if (itemsInSlots[i] > maxCapacity) {
                std::cout << "Slot " << i << " is overloaded! Remove items." << std::endl;
            }
        }
    }

private:
    int numSlots;
    int maxCapacity;
    std::vector<int> itemsInSlots;
};

int main() {
    // Adjust the number of slots as needed
    int numSlots = 5; 
    // Maximum capacity for each slot
    int maxCapacity = 100;

    SlotTracker slotTracker(numSlots, maxCapacity);

    // Simulate tracking items in slots
    slotTracker.TrackItemInSlot(0, 80);
    slotTracker.TrackItemInSlot(1, 110);
    slotTracker.TrackItemInSlot(2, 95);

    // Display empty slots
    std::vector<int> emptySlots = slotTracker.GetEmptySlots();
    std::cout << "Slots that need to be filled: ";
    for (int slot : emptySlots) {
        std::cout << slot << " ";
    }
    std::cout << std::endl;

    return 0;
}
