#include<iostream>
#include<fstream>
using namespace std;

int main() {
    fstream f("draft.txt", ios::in | ios::out);
    string content = "", line;
    while (getline(f, line))
        content += line + "\n";

    int pos = content.find("teh");
    if (pos == string::npos) {
        cout << "Word 'teh' not found." << endl;
        f.close();
        return 0;
    }

    f.seekp(pos);
    f.write("the", 3);
    f.close();
    cout << "Replaced first 'teh' with 'the'." << endl;
    return 0;
}
