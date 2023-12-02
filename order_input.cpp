import datetime
from item_scanner import inventory

def expired(expiration_date):
    today = datetime.date.today()
    exp_date = datetime.datetime.strptime(expiration_date, "%Y-%m-%d").date()
    return exp_date < today

def get_item(selected_item):
    items = list(inventory.keys())
    if 1 <= selected_item <= len(items):
        item_name = items[selected_item - 1]
        expiration_date = inventory[item_name]["expiration_date"]
        return item_name, expiration_date
    else:
        return None

def confirm_purchase(item_name):
    confirm = input(f"Would you like to purchase one {item_name} (y or n)? ").lower()
    if confirm == "n":
        print("Purchase cancelled.")
        return False
    elif confirm == "y":
        return True
    else:
        print("Invalid answer. Please enter 'y' or 'n'.")
        return confirm_purchase(item_name)

def purchase(item_name):
    if item_name in inventory and inventory[item_name]["quantity"] > 0:
        print(f"Purchase of one {item_name} confirmed.")
        inventory[item_name]["quantity"] -= 1
    else:
        print("This item is out of stock.")

while True:
    try:
        selected_item = int(input("Enter the number of your selection (1-40) (use 0 to quit): "))
        if selected_item == 0:
            break
        selection = get_item(selected_item)
        if selection:
            item_name, expiration_date = selection
            print(f"You have selected: {item_name}")
            if expired(expiration_date):
                print("This item is expired.")
            else:
                if confirm_purchase(item_name):
                    purchase(item_name)
        else:
            print("Invalid selection.")
    except ValueError:
        print("Invalid input.")
