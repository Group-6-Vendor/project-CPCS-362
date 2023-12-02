Project Vending Machine Group 6


# Description:
This program demo is meant to show how we can improve the modern vending machine for both the customer, restocker and the managers.

# How-To-Run

Download the executeable in the Release tab. Place the program into a folder. The program will need to create files on the computer in order to function, so a folder is the best location to put it in. The program will only create .txt files, but windows will flag this program as malware. This is due to the fact that I am not able to sign the program.

# Known Issues/Bugs
- Error handling / Return values not consistent in Addition Tracker (resolved)
- Payment Processing feature did not account for negative values (resolved)
- Customer Display does not account for dynamic product selection (resolved)

# Known Missing Release 3 Featuress
- Design a customer UI
    - Customer needs a screen / buttons to be able to interact with vending machine.
    - Interface also needs to accept money/form of payment and return change.
- Restock List
    - VM must maintain a live record of recalled, expired, added, or aren't selling items.
    - Needs to also maintain items with different expiration dates.
    - Essential job of this feature is to notify the stocker of where and how much of their quantity is needed.
- Scan / Barcode for Restocker
    - This barcode essentially needs to associate and hold the scanned item's data (expiration date, future recalls, price, live inventory of items, and name).
- Data Management Tool
    - This feature needs to enable being connected to the desired machine remotely
    - Allows vending maching stats to be actively viewed at all times
    - VM must be enabled to receive communication from remote manager
    - VM should keep active market/sales logs (what's selling and what isn't) and report status to manage
