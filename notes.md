To compile code for part 1 (Consumer/Restocker), do 
```x86_64-w64-mingw32-g++ -o your_executable main.cpp expire_tracker.cpp add_items.cpp clear_items.cpp delete_items.cpp -std=c++11 -static```
The ```-static``` part will bundle the libraries into the .exe for easy use running program.
