#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream f(filename);
    if (!f) {
        cout << "File not found." << endl;
        return 1;
    }

    long long offset;
    cout << "Enter byte offset: ";
    cin >> offset;

    cout << "Pointer before seekg: " << f.tellg() << "\n";
    f.seekg(offset);
    cout << "Pointer after seekg : " << f.tellg() << "\n";

    char buf[101] = {};
    f.read(buf, 100);
    cout << "\n--- Next 100 characters ---\n";
    cout << buf << "\n";

    f.close();
    return 0;
}
