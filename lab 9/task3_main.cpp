#include<iostream>
#include "Book.h"
using namespace std;

int main() {
    Book b("The Alchemist", "Paulo Coelho", "978-0062315007");
    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;
    return 0;
}
