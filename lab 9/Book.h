#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;

class Book {
    string title, author, isbn;
public:
    Book(string t, string a, string i);
    string getTitle();
    string getAuthor();
    string getISBN();
};

#endif
