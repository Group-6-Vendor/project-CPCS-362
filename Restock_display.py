# Temp solution: should import from Addition Tracker
class AdditionTracker:
    def __init__(self):
        self.additions = []

    def track_addition(self, item, quantity):
        # Track the addition of items
        self.additions.append((item, quantity))

# Temp solution: should import from Expiration Tracker
class ExpirationTracker:
    def __init__(self):
        self.expirations = []

    def track_expiration(self, item, expiration_date):
        # Track the expiration of items
        self.expirations.append((item, expiration_date))

# Temp solution: should import from Slot Tracker
class SlotTracker:
    def __init__(self):
        self.slots = {}

    def track_slot(self, item, slot_number):
        # Track the slot number for items
        self.slots[item] = slot_number
# Temp solution: should import from Purchase Tracker
class PurchaseTracker:
    def __init__(self):
        self.purchases = []

    def track_purchase(self, item, quantity):
        # Track purchases of items
        self.purchases.append((item, quantity))

# Create instances of each tracker
addition_tracker = AdditionTracker()
expiration_tracker = ExpirationTracker()
slot_tracker = SlotTracker()
purchase_tracker = PurchaseTracker()

# Created sample data for the trackers to show that it works
addition_tracker.track_addition("Item A", 10)
expiration_tracker.track_expiration("Item A", "2023-10-31")
slot_tracker.track_slot("Item A", 5)
purchase_tracker.track_purchase("Item A", 5)

# Display relevant tracked information to restockers
def display_information():
    print("Additions:")
    for item, quantity in addition_tracker.additions:
        print(f"{item}: {quantity} added")

    print("\nExpirations:")
    for item, expiration_date in expiration_tracker.expirations:
        print(f"{item}: Expires on {expiration_date}")

    print("\nSlots:")
    for item, slot_number in slot_tracker.slots.items():
        print(f"{item} is in slot {slot_number}")

    print("\nPurchases:")
    for item, quantity in purchase_tracker.purchases:
        print(f"{item}: {quantity} purchased")

# Call the display function
display_information()
