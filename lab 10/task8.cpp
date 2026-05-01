#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream f("article.txt");

    f.seekg(0, ios::end);
    long long size = f.tellg();
    f.seekg(size / 2);

    string line;
    getline(f, line);

    for (int i = 0; i < 10 && getline(f, line); i++)
        cout << line << "\n";

    f.close();
    return 0;
}
