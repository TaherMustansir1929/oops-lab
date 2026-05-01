#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string name, email, choice;
    ofstream f("signup.txt", ios::app);

    do {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter email: ";
        getline(cin, email);
        f << "Name: " << name << ", Email: " << email << "\n";
        cout << "Add another? (y/n): ";
        getline(cin, choice);
    } while (choice == "y");

    f.close();
    cout << "Saved to signup.txt" << endl;
    return 0;
}
