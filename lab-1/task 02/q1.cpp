#include <iostream>
#include <string>
using namespace std;

struct Book {
  string title;
  string author;
  int year;
  string genre;
};

void displayBook(Book b) {
  cout << "\nTitle: " << b.title << endl;
  cout << "Author: " << b.author << endl;
  cout << "Year: " << b.year << endl;
  cout << "Genre: " << b.genre << endl;
}

int searchBook(Book books[], int n, string s) {
  for (int i = 0; i < n; i++) {
    if (books[i].title == s || books[i].author == s) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, choice, idx;
  string search;

  cout << "Enter number of books: ";
  cin >> n;
  cin.ignore();

  Book books[n];

  for (int i = 0; i < n; i++) {
    cout << "\nEnter details for book " << i + 1 << ":" << endl;
    cout << "Title: ";
    getline(cin, books[i].title);
    cout << "Author: ";
    getline(cin, books[i].author);
    cout << "Year: ";
    cin >> books[i].year;
    cin.ignore();
    cout << "Genre: ";
    getline(cin, books[i].genre);
  }

  while (true) {
    cout << "\n1. Display all books\n2. Search book\n3. Update book\n4. "
            "Exit\nChoice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
      for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << ":";
        displayBook(books[i]);
      }
    } else if (choice == 2) {
      cout << "Enter title or author to search: ";
      getline(cin, search);
      idx = searchBook(books, n, search);
      if (idx != -1) {
        cout << "Book found:";
        displayBook(books[idx]);
      } else {
        cout << "Book not found" << endl;
      }
    } else if (choice == 3) {
      cout << "Enter book number to update (1-" << n << "): ";
      cin >> idx;
      cin.ignore();
      idx--;
      if (idx >= 0 && idx < n) {
        cout << "Title: ";
        getline(cin, books[idx].title);
        cout << "Author: ";
        getline(cin, books[idx].author);
        cout << "Year: ";
        cin >> books[idx].year;
        cin.ignore();
        cout << "Genre: ";
        getline(cin, books[idx].genre);
        cout << "Book updated!" << endl;
      }
    } else {
      break;
    }
  }

  return 0;
}