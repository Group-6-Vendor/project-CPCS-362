#!/bin/bash


x86_64-w64-mingw32-g++ -o Customer-Restocker main.cpp expire_tracker.cpp add_items.cpp clear_items.cpp delete_items.cpp purchase_item.cpp -std=c++11 -static
