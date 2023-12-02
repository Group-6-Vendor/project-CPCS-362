#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>      // std::get_time
#include <chrono>

#pragma once

#ifdef EXPIRE_TRACKER_H
#define EXPIRE_TRACKER_H
#endif 
struct VendingMachineItem{
    std::string name;
    int slotNumber;             // New member to the group. Should be when we do like 3A. This should be == 3
    std::string location;       // this should be like equal to A
    std::string expirationDate;
    int quantity;               // Not Originally here, so DEL if needed!
};

std::vector<struct VendingMachineItem> expire_tracker(const std::string&);

