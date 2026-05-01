#include <iostream>
#include <string>
using namespace std;

struct Product {
  int id;
  string name;
  float price;
  int qty;
};

Product products[100];
int count = 0;

void addProduct(int id, string name, float price, int qty) {
  products[count].id = id;
  products[count].name = name;
  products[count].price = price;
  products[count].qty = qty;
  count++;
  cout << "Product added successfully!" << endl;
}

void displayProduct(int id) {
  for (int i = 0; i < count; i++) {
    if (products[i].id == id) {
      cout << "\nProduct ID: " << products[i].id << endl;
      cout << "Name: " << products[i].name << endl;
      cout << "Price: Rs. " << products[i].price << endl;
      cout << "Quantity: " << products[i].qty << endl;
      return;
    }
  }
  cout << "Product not found!" << endl;
}

void updateProduct(int id, float price, int qty) {
  for (int i = 0; i < count; i++) {
    if (products[i].id == id) {
      products[i].price = price;
      products[i].qty = qty;
      cout << "Product updated successfully!" << endl;
      return;
    }
  }
  cout << "Product not found!" << endl;
}

void removeProduct(int id) {
  for (int i = 0; i < count; i++) {
    if (products[i].id == id) {
      for (int j = i; j < count - 1; j++) {
        products[j] = products[j + 1];
      }
      count--;
      cout << "Product removed successfully!" << endl;
      return;
    }
  }
  cout << "Product not found!" << endl;
}

int main() {
  int choice, id, qty;
  string name;
  float price;

  while (true) {
    cout << "\n1. Add Product\n2. Display Product\n3. Update Product\n4. "
            "Remove Product\n5. Exit\nChoice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter ID: ";
      cin >> id;
      cin.ignore();
      cout << "Enter Name: ";
      getline(cin, name);
      cout << "Enter Price: ";
      cin >> price;
      cout << "Enter Quantity: ";
      cin >> qty;
      addProduct(id, name, price, qty);
    } else if (choice == 2) {
      cout << "Enter Product ID: ";
      cin >> id;
      displayProduct(id);
    } else if (choice == 3) {
      cout << "Enter Product ID: ";
      cin >> id;
      cout << "Enter New Price: ";
      cin >> price;
      cout << "Enter New Quantity: ";
      cin >> qty;
      updateProduct(id, price, qty);
    } else if (choice == 4) {
      cout << "Enter Product ID: ";
      cin >> id;
      removeProduct(id);
    } else {
      break;
    }
  }

  return 0;
}