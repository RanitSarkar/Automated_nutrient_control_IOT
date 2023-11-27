import tkinter as tk
from tkinter import ttk

class HydroponicsInterface:
    def __init__(self, root):
        self.root = root
        self.root.title("Hydroponics Dozer Interface")

        # Create and place widgets
        self.label = ttk.Label(root, text="Enter specifications:")
        self.label.grid(row=0, column=0, padx=10, pady=10)

        self.ph_entry = ttk.Entry(root, width=10)
        self.ph_entry.grid(row=1, column=0, padx=10, pady=5)

        self.tds_entry = ttk.Entry(root, width=10)
        self.tds_entry.grid(row=1, column=1, padx=10, pady=5)

        self.submit_button = ttk.Button(root, text="Submit", command=self.submit_specifications)
        self.submit_button.grid(row=2, column=0, columnspan=2, pady=10)

    def submit_specifications(self):
        ph_value = self.ph_entry.get()
        tds_value = self.tds_entry.get()

        # Add logic to send specifications to Arduino (e.g., via serial communication)
        print(f"pH: {ph_value}, TDS: {tds_value} submitted")

if __name__ == "__main__":
    root = tk.Tk()
    app = HydroponicsInterface(root)
    root.mainloop()
