# Get the total price of the selected item
# Temporary solution:  should get the order from order input 
total_price = float(input("Enter the total price: $")) 

# Get the total price of the selected item
total_price = float(input("Enter the total price: $"))

# Initialize variables for the customer's payment and change
customer_payment = 0.0

# Function to insert money in cash and coins
def insert_money():
    global customer_payment
    while True:
        try:
            money = float(input("Insert money or coins (enter 0 to finish): $"))
            if money == 0:
                break
            customer_payment += money
        except ValueError:
            print("Invalid input. Please enter a valid amount.")

# Get the customer's payment in cash and coins
print("Insert cash and coins to pay for the item:")
insert_money()

# Calculate the change and provide the receipt
while customer_payment < total_price:
    print("Remaining balance: ${:.2f}".format(total_price - customer_payment))
    print("Insufficient payment. Please provide more cash and coins.")
    insert_money()

change = customer_payment - total_price

print("Thank you for your purchase!")
print(f"Total price: ${total_price:.2f}")
print(f"Customer payment: ${customer_payment:.2f}")
print(f"Change: ${change:.2f}")