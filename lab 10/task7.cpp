#include<iostream>
#include<fstream>
using namespace std;

struct Student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;
    cin.ignore();

    Student s;
    ofstream fw("students.dat", ios::binary);
    for (int i = 0; i < n; i++) {
        cout << "Name: ";
        cin.getline(s.name, 50);
        cout << "ID: ";
        cin >> s.id;
        cout << "GPA: ";
        cin >> s.gpa;
        cin.ignore();
        fw.write((char*)&s, sizeof(s));
    }
    fw.close();

    ifstream fr("students.dat", ios::binary);
    cout << "\n--- Student Records ---\n";
    while (fr.read((char*)&s, sizeof(s))) {
        cout << "Name: " << s.name << ", ID: " << s.id << ", GPA: " << s.gpa << "\n";
    }
    fr.close();
    return 0;
}
