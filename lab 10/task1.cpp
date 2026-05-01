#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string name, msg;
    cout << "Enter recipient name: ";
    getline(cin, name);
    cout << "Enter message: ";
    getline(cin, msg);

    ofstream f("greeting.txt");
    f << "Dear " << name << ",\n" << msg << "\nBest Regards!";
    f.close();

    cout << "Written to greeting.txt" << endl;
    return 0;
}
