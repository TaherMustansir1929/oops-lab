#include "Book.h"

Book::Book(string t, string a, string i) {
    title = t;
    author = a;
    isbn = i;
}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return isbn; }
