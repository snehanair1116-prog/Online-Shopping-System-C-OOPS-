#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ------------------- BASE PRODUCT -------------------
class Product {
protected:
    int id;
    string name;
    float price;
    string category;
    int stock;

public:
    Product(int i, string n, float p, string cat, int s = 10) 
        : id(i), name(n), price(p), category(cat), stock(s) {}

    virtual ~Product() {}

    virtual float getPrice() { return price; }
    int getID() { return id; }
    string getName() { return name; }
    int getStock() { return stock; }
    
    void reduceStock() { if(stock > 0) stock--; }

    virtual void display() {
        cout << left << setw(4) << id << setw(20) << name 
             << setw(15) << category << setw(10) << getPrice() 
             << "Stock: " << stock << endl;
    }
};

// ------------------- DERIVED PRODUCTS -------------------
class DiscountProduct : public Product {
private:
    float discount;
public:
    DiscountProduct(int i, string n, float p, float d, int s = 10)
        : Product(i, n, p, "Sale", s), discount(d) {}

    float getPrice() override { return price - (price * discount / 100); }

    void display() override {
        cout << left << setw(4) << id << setw(20) << name 
             << setw(15) << category << setw(10) << getPrice() 
             << "Stock: " << stock << " (" << discount << "% OFF)" << endl;
    }
};

// ------------------- SHOP CLASS -------------------
class Shop {
private:
    vector<Product*> inventory;

public:
    ~Shop() { for (Product* p : inventory) delete p; }

    void addProduct(Product* p) { inventory.push_back(p); }

    void showInventory() {
        cout << "\n" << string(60, '=') << endl;
        cout << left << setw(4) << "ID" << setw(20) << "Product Name" 
             << setw(15) << "Category" << setw(10) << "Price" << "Status" << endl;
        cout << string(60, '-') << endl;
        for (auto p : inventory) p->display();
        cout << string(60, '=') << endl;
    }

    Product* findProduct(int id) {
        for (auto p : inventory) {
            if (p->getID() == id) return p;
        }
        return nullptr;
    }
};

// ------------------- CART CLASS -------------------
class Cart {
private:
    vector<Product*> items;
public:
    void addProduct(Product* p) {
        if(p->getStock() > 0) {
            items.push_back(p);
            p->reduceStock();
            cout << "Successfully added " << p->getName() << " to cart!\n";
        } else {
            cout << "Sorry, " << p->getName() << " is out of stock!\n";
        }
    }

    void showCart() {
        if (items.empty()) {
            cout << "\nYour cart is empty!" << endl;
            return;
        }
        float total = 0;
        cout << "\n--- YOUR SHOPPING CART ---" << endl;
        for (auto p : items) {
            cout << "- " << left << setw(20) << p->getName() << "$" << p->getPrice() << endl;
            total += p->getPrice();
        }
        cout << "--------------------------" << endl;
        cout << "TOTAL BILL: $" << total << endl;
    }
};

// ------------------- INVENTORY POPULATION -------------------
void seedInventory(Shop &s) {
    // Basic Products (Electronics & Home)
    s.addProduct(new Product(1, "Laptop", 45000, "Electronics", 5));
    s.addProduct(new Product(2, "Smartphone", 15000, "Electronics", 8));
    s.addProduct(new Product(3, "Blender", 2500, "Kitchen", 12));
    s.addProduct(new Product(4, "Desk Lamp", 800, "Home", 20));
    s.addProduct(new Product(5, "Gaming Mouse", 1200, "Electronics", 15));
    s.addProduct(new Product(6, "Coffee Mug", 300, "Kitchen", 50));
    s.addProduct(new Product(7, "Yoga Mat", 1100, "Fitness", 10));
    s.addProduct(new Product(8, "Backpack", 2200, "Travel", 7));
    s.addProduct(new Product(9, "Electric Kettle", 1800, "Kitchen", 4));
    s.addProduct(new Product(10, "Table Fan", 3200, "Home", 6));

    // Discounted Products
    s.addProduct(new DiscountProduct(11, "Nike Shoes", 5000, 20, 5));
    s.addProduct(new DiscountProduct(12, "Leather Jacket", 8000, 30, 3));
    s.addProduct(new DiscountProduct(13, "Bluetooth Speaker", 2000, 15, 10));
    s.addProduct(new DiscountProduct(14, "Sunglasses", 1500, 50, 25));
    s.addProduct(new DiscountProduct(15, "Winter Hoodie", 2500, 25, 12));
    s.addProduct(new DiscountProduct(16, "Cereal Bowls", 600, 10, 40));
    s.addProduct(new DiscountProduct(17, "Mechanical Keyboard", 4000, 10, 5));
    s.addProduct(new DiscountProduct(18, "Water Bottle", 500, 5, 100));
    s.addProduct(new DiscountProduct(19, "Wrist Watch", 3500, 40, 8));
    s.addProduct(new DiscountProduct(20, "Study Table", 7000, 15, 2));
}

// ------------------- MAIN -------------------
int main() {
    Shop myShop;
    Cart myCart;
    seedInventory(myShop);

    int choice, id;
    cout << "Welcome to the Mega Store!" << endl;

    do {
        cout << "\nMain Menu:\n1. View All Products\n2. Add Product to Cart\n3. View My Cart\n4. Exit\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myShop.showInventory();
                break;
            case 2:
                cout << "Enter Product ID to buy: ";
                cin >> id;
                if (Product* p = myShop.findProduct(id)) {
                    myCart.addProduct(p);
                } else {
                    cout << "Invalid ID!" << endl;
                }
                break;
            case 3:
                myCart.showCart();
                break;
            case 4:
                cout << "Exiting... Thank you for visiting!" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}