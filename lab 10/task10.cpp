#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string msg, choice;
    do {
        fstream f("backup_log.txt", ios::app | ios::out);
        cout << "Enter log message: ";
        getline(cin, msg);
        f << msg << "\n";
        long long sz = f.tellp();
        f.close();
        cout << "File size: " << sz << " bytes\n";
        cout << "Add another? (y/n): ";
        getline(cin, choice);
    } while (choice == "y");
    return 0;
}
