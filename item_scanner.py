inventory = {}

def add_item(name, quantity, expiration_date, slot):
    if name not in inventory:
        inventory[name] = {
            "quantity": 0,
            "expiration_date": "",
            "slot": 0
        }
    inventory[name]["quantity"] += quantity
    inventory[name]["expiration_date"] = expiration_date

def display_inventory():
    print("Current Inventory:")
    for name, item_info in inventory.items():
        total_quantity = item_info["quantity"]
        expiration_date = item_info["expiration_date"]
        print(f"{name}: {total_quantity} items, Expiration Date: {expiration_date}")

while True:
    print("\nStock Item (or type 'quit' to exit):")

    name = input("Enter item name: ").strip()

    if name.lower() == "quit":
        break
    
    try:
        quantity = int(input("Enter quantity: "))
        expiration_date = input("Enter expiration date (YYYY-MM-DD): ")
        slot = int(input("Enter slot: "))
        
        add_item(name, quantity, expiration_date, slot)
        print(f"{quantity} {name} added to inventory in slot {slot}.")
    except ValueError:
        print("Invalid input. Please enter a valid quantity.")

display_inventory()