#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
    ifstream f("story.txt");
    string line, word;
    while (getline(f, line)) {
        istringstream ss(line);
        while (ss >> word)
            cout << word << "\n";
    }
    f.close();
    return 0;
}
