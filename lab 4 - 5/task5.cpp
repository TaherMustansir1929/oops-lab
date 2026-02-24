#include<iostream>
using namespace std;

class Dept {
public:
    string name, code;
};

class Student {
public:
    string name;
    int age;
    Dept dept;
};

int main() {
    Student students[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter name, age, dept name, dept code: ";
        cin >> students[i].name >> students[i].age >> students[i].dept.name >> students[i].dept.code;
    }
    for (int i = 0; i < 3; i++) {
        cout << students[i].name << " | " << students[i].age << " | "
             << students[i].dept.name << " | " << students[i].dept.code << endl;
    }
}
