#include <iostream>
#include <string>
using namespace std;

class Shop {
private:
    string items[100];
    double prices[100];
    int count;

public:
    Shop() {
        count = 0;
    }
    
    void addItem() {
        string name;
        double price;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
        
        items[count] = name;
        prices[count] = price;
        count++;
        cout << "Item added." << endl;
    }
    
    void getItems() {
        cout << "\nItems in shop:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }
    
    void editPrice() {
        string name;
        double newPrice;
        cout << "Enter item name: ";
        cin >> name;
        
        for (int i = 0; i < count; i++) {
            if (items[i] == name) {
                cout << "Enter new price: ";
                cin >> newPrice;
                prices[i] = newPrice;
                cout << "Price updated." << endl;
                return;
            }
        }
        cout << "Item not found." << endl;
    }
    
    void viewAll() {
        cout << "\nAll items with prices:" << endl;
        for (int i = 0; i < count; i++) {
            cout << items[i] << " - Rs. " << prices[i] << endl;
        }
    }
    
    void generateReceipt() {
        string itemName[50];
        int qty[50];
        int n;
        
        cout << "How many different items purchased? ";
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cout << "Enter item name: ";
            cin >> itemName[i];
            cout << "Enter quantity: ";
            cin >> qty[i];
        }
        
        cout << "\n===== RECEIPT =====" << endl;
        double total = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < count; j++) {
                if (items[j] == itemName[i]) {
                    double amt = prices[j] * qty[i];
                    cout << itemName[i] << " x " << qty[i] << " = Rs. " << amt << endl;
                    total = total + amt;
                }
            }
        }
        
        cout << "-------------------" << endl;
        cout << "Total: Rs. " << total << endl;
        cout << "===================" << endl;
    }
};

int main() {
    Shop s;
    int choice;
    
    while (true) {
        cout << "\n1. Add item" << endl;
        cout << "2. Get items" << endl;
        cout << "3. Edit price" << endl;
        cout << "4. View all" << endl;
        cout << "5. Generate receipt" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            s.addItem();
        } else if (choice == 2) {
            s.getItems();
        } else if (choice == 3) {
            s.editPrice();
        } else if (choice == 4) {
            s.viewAll();
        } else if (choice == 5) {
            s.generateReceipt();
        } else if (choice == 6) {
            break;
        }
    }
    
    return 0;
}
