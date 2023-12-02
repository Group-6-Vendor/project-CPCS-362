import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

class VendingMachine:
    def __init__(self, sender_email, sender_password):
        # Initialize the vending machine with some items and stock levels
        self.items = {
            "Item A": 10,
            "Item B": 8,
            "Item C": 15,
        }
        self.sender_email = sender_email
        self.sender_password = sender_password

    def send_status_report(self, manager_email, subject, message):
        # Create the email message
        msg = MIMEMultipart()
        msg["From"] = self.sender_email
        msg["To"] = manager_email
        msg["Subject"] = subject
        msg.attach(MIMEText(message, "plain"))

        try:
            # Connect to the SMTP server (Gmail in this example)
            server = smtplib.SMTP("smtp.gmail.com", 587)
            server.starttls()
            server.login(self.sender_email, self.sender_password)

            # Send the email
            server.sendmail(self.sender_email, manager_email, msg.as_string())

            # Close the connection
            server.quit()

            print("Status report sent successfully!")
        except smtplib.SMTPException as e:
            print("Failed to send status report: ", str(e))

    def report_status(self, manager_email):
        # Generate a status report message
        status_report = "Vending Machine Status Report:\n\n"
        for item, stock in self.items.items():
            status_report += f"{item}: {stock} available\n"

        # Send the status report via email
        subject = "Vending Machine Status Report"
        self.send_status_report(manager_email, subject, status_report)

    def restock_item(self, item, quantity):
        # Restock a specific item with the given quantity
        if item in self.items:
            self.items[item] += quantity
        else:
            print("Item needs to be restocked in the vending machine.")

# Example usage
# Replace with your email and password
sender_email = "your_email_address"
sender_password = "your_password"

vending_machine = VendingMachine(sender_email, sender_password)
manager_email = "manager_email_address"  # Replace with the manager's email

# Report the initial status
vending_machine.report_status(manager_email)

# Restock an item (e.g., Item A with 5 more units)
vending_machine.restock_item("Item A", 5)

# Report the updated status
vending_machine.report_status(manager_email)
