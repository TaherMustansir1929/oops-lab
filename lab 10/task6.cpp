#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream f("secret.txt");
    char c;
    int count = 0;
    while (f.get(c)) {
        if (c >= 'A' && c <= 'Z')
            count++;
    }
    f.close();
    cout << "Uppercase letter count: " << count << endl;
    return 0;
}
