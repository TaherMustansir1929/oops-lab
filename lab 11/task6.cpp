#include<iostream>
using namespace std;

class InvalidAgeException {
public:
    string msg = "Age must be between 1 and 119";
};
class InvalidSalaryException {
public:
    string msg = "Salary must be positive";
};
class InvalidHeightException {
public:
    string msg = "Height must be positive";
};

int main() {
    int age;
    double salary, height;

    cout << "Enter age: ";
    cin >> age;
    try {
        if (age <= 0 || age >= 120) throw InvalidAgeException();
        cout << "Age accepted: " << age << endl;
    } catch (InvalidAgeException &e) {
        cout << "InvalidAgeException caught: " << e.msg << endl;
    }

    cout << "Enter salary: ";
    cin >> salary;
    try {
        if (salary <= 0) throw InvalidSalaryException();
        cout << "Salary accepted: " << salary << endl;
    } catch (InvalidSalaryException &e) {
        cout << "InvalidSalaryException caught: " << e.msg << endl;
    }

    cout << "Enter height: ";
    cin >> height;
    try {
        if (height <= 0) throw InvalidHeightException();
        cout << "Height accepted: " << height << endl;
    } catch (InvalidHeightException &e) {
        cout << "InvalidHeightException caught: " << e.msg << endl;
    }

    return 0;
}
