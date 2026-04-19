# Online-Shopping-System-C-OOPS-
# Online Shopping System (C++)

A console-based Online Shopping System built using **Object-Oriented Programming (OOP)** principles in C++. This project simulates a real-world store where users can browse an inventory of 20+ items, add them to a cart, and see a calculated bill with discounts and stock management.

## 🚀 Features
- **Dynamic Inventory:** Over 20 items across categories like Electronics, Kitchen, and Fitness.
- **Stock Management:** Real-time stock updates (items decrease when added to cart).
- **Discount System:** Automatic price calculation for sale items.
- **Formatted UI:** Clean table-style display using the `<iomanip>` library.

## 🛠 OOP Concepts Used
- **Encapsulation:** Data members are protected/private to ensure data security.
- **Inheritance:** `DiscountProduct` and `Electronics` classes inherit from the base `Product` class.
- **Polymorphism:** Used virtual functions (`display`, `getPrice`) for dynamic binding.
- **Composition:** The `Shop` and `Cart` classes manage collections of `Product` objects.

## 💻 How to Run
1. Ensure you have a C++ compiler installed (like GCC/G++).
2. Clone the repository:
   ```bash
   git clone [https://github.com/YourUsername/Online-Shopping-System.git](https://github.com/YourUsername/Online-Shopping-System.git)
