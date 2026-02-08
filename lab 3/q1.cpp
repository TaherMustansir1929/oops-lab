#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book() {
        title = "Untitled";
        author = "Anonymous";
        price = 0.0;
    }
    
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }
    
    Book(const Book &b) {
        title = b.title;
        author = b.author;
        price = b.price;
    }
    
    Book(string t, string a = "Unknown", double p = 0.0) {
        title = t;
        author = a;
        price = p;
    }
    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
};

int main() {
    Book b1;
    cout << "Book 1 (Default Constructor):" << endl;
    b1.display();
    
    Book b2("C++ Programming", "Bjarne", 500.0);
    cout << "Book 2 (Parameterized Constructor):" << endl;
    b2.display();
    
    Book b3(b2);
    cout << "Book 3 (Copy Constructor):" << endl;
    b3.display();
    
    Book b4("Data Structures");
    cout << "Book 4 (Default Arguments - only title):" << endl;
    b4.display();
    
    Book b5("Algorithms", "Thomas");
    cout << "Book 5 (Default Arguments - title and author):" << endl;
    b5.display();
    
    return 0;
}
