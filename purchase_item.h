// purchase_item.h

#pragma once


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>

#include "expire_tracker.h"

#ifdef PURCHASE_ITEM_H
#define PURCHASE_ITEM_H
#endif

/*
struct VendingMachineItem {
    std::string name;
    std::string location;
    std::string expirationDate;
    int quantity;
}; */


std::vector<VendingMachineItem> getInventory(const std::string& machineID);


void updateInventory(const std::string& machineID, const std::vector<VendingMachineItem>& inventory);

bool isItemExpired(const VendingMachineItem& item);

void purchaseItem(const std::string& machineID);
