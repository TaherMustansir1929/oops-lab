#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream f("diary.txt", ios::app);
    string line;
    cout << "Enter diary entries (type 'exit' to stop):\n";
    while (true) {
        getline(cin, line);
        if (line == "exit") break;
        f << line << "\n";
    }
    f.close();
    cout << "Saved to diary.txt" << endl;
    return 0;
}
